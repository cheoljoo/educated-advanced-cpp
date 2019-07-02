

# Day2

------------

## new
- https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h
```cpp
template<typename TYPE>
typename std::enable_if<!traits<TYPE>::has_trivial_copy>::type
inline
copy_type(TYPE* d, const TYPE* s, size_t n) {
    while (n > 0) {
        n--;
        new(d) TYPE(*s);    // <== 생성자만 호출
        d++, s++;
    }
}
```

### 메모리 할당과 생성자 분리
- 핵심 1. new의 2가지 사용법
    - new Point(1,1) : 메모리 할당 후 생성자 호출
    - new(p) Point(1,1) : 이미 존재하는 메모리(주소p)에 생성자 호출
        - placement new (위치 지정 new)
- 핵심 2. 생성사 호출 없이 메모리만 할당하는 방법
    - operator new (메모리크기)
- 핵심 3.
    - delete p1; 소멸자 호출 , 메모리 해지
    - operator delete(p1) : 메모리만 해지
- [source 1_new1  103 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new1.cpp)
- "android source github"   aosp-mirror
    - platform_system_core utils/TypeHelpers.h    enable_if , new 등 모두 들어가 있는 code
    - https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h
        - copy_type
```cpp
    // malloc : 메모리만 할당
    // new : 메모리를 할당 + 생성사 호출
    Point* p1 = new Point(0,0);
    delete p1; // 소멸자 호출 후 메모리 해지

    // 메모리할당과 생성자 호출 분리
    // 1. 메모리만 할당
    Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));    // malloc과 유사
                        // operator new의 반환값이 void *

    std::cout << "주소: " << p2 << std::endl;

    // 2. 할당된 메모리에 생성자 호출
    new(p2) Point(0,0);

    // 메모리 할당과 생성자 호출을 분리한 경우
    // 소멸자 호출과 메모리 해지도 분리한다.

    // 3. 소멸자 호출
    p2->~Point();

    // 4. 메모리만 해지
    operator delete(p2);
```

------------

### 0,0으로 초기화된 Point를 힙에 10개 만들자.
- 메모리 할당과 생성자 호출을 분리하면 항상 편리하다.
    - <default 생성자가 없을때 분리해서 처리> : 다른 사람이 짠 library를 사용하는 경우에는 default constructor가 없을수 있다.
- [source 1_new2 103 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new2.cpp)
```cpp
    // 1. 0,0으로 초기화된 point를 힙에 한개 만들어 보세요.
    Point* p1 = new Point(0,0);

    // 2.  0,0으로 초기화된 Point를 힙에 10개 만들어보세요.
    // default생성자가 Point[]에 대해서는 없다.
    // Point* p2 = new Point[10];  // error. 디폴트생성자가 필요

    // 메모리 할당과 생성자 호출을 분리하면 항상 편리하다.
    // <default 생성자가 없을때 분리해서 처리>
    Point* p2 = static_cast<Point*>( operator new(sizeof(Point)*10) );
        // 아직 객체는 아님. 생성자가 호출 안됨.

    // 10개의 메모리에 대해서 생성자 호출
    for(int i=0;i<10;i++){
        new(&p2[i]) Point(0,0);     // 기출시험문제
    }

    // 사용후에는
    // 1. 소멸자 호출
    for(int i=0;i<10;i++){
        p2[i].~Point();
    }

    // 메모리만 해지
    operator delete(p2);

```

------------

###  vector의 메모리 관리 기술
- 생성된 것을 지우기보다는 향후 할당을 위해서 간직한다.
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    // 1. vector의 메모리 관리 기술
    std::vector<int> v(10);

    v.resize(7); // 원리를 생각해봅시다.
        // 새로 할당해서 copy하지 않고 , 그냥 재사용하면서 capacity라는 변수로 관리

    std::cout << v.size() << std::endl;     // 7
    std::cout << v.capacity() << std::endl;     // 10

    v.push_back(5);
    std::cout << v.size() << std::endl;     // 8
    std::cout << v.capacity() << std::endl;     // 10

    v.shrink_to_fit();
    std::cout << v.size() << std::endl;     // 8
    std::cout << v.capacity() << std::endl;     // 8

    v.push_back(5);
    std::cout << v.size() << std::endl;     // 9
    std::cout << v.capacity() << std::endl;     // 16  더 크게

```

------------

### vector resize
- v(10) -> v.resize(3) : 줄어든 메모리는 파괴하지 않습니다. 하지만 소멸자를 호출해야 합니다. 소멸자의 명시적 호출이 필요합니다.
- v.resize(3) -> v.resize(4) : 메모리는 이미 있으므로, 생성자의 명시적 호출이 필요합니다. (placement new를 사용해서 생성자 호출)
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------


### vector를 만들어보자
- vector를 만들어보자
    - buff = new T[z];와 같이 하지 말자 T에 대한 default constructor가 꼭 있어야 한다.
    - 메모리 할당자와 생성자를 분리하자.
- C++ Programming Language : C++ 창시자 책 (stroustrub)
    - STL 의 내부를 보여준다.
- [source 1_new4 103 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new4.cpp)
```cpp
template <typename T> class vector
{
    T* buff;
    int size;
    int capacity;
public:
    vector(int sz, T value=T()) : size(sz),capacity(sz)
    {
        // buff = new T[sz];   // T의 default 생성자가 있어야 한다.
                            // 103 page에서 이렇게 하지 말라는 것이다.

        // 1. 메모리 먼저 할당
        buff = static_cast<T*>(operator new(sizeof(T) * size));

        // 2. 생성자 호출
        int cnt = 0;
        try
        {
            for(;cnt<size;cnt++){
                // new(&buff[cnt]) T; // default constructor 호출
                new(&buff[cnt]) T(value); // 복사 생성자 호출
            }
        } catch(...)
        {
            // 복사 생성자 호출중 예외가 발생하면
            // 생성이 완료된 객체는 소멸자 호출
            for(int i=0;i<cnt;i++)
                buff[i].~T();

            // 메모리 해지
            operator delete(buff);

            // 발생된 예외를 밖으로 전달
            throw;
        }
    }
};

```

------------


### 많이 사용하는 try catch를 std에서 제공하는 함수로 대치
- 
- [source 1_new4](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new4.cpp)
```cpp
template <typename T> class vector
{
    T* buff;
    int size;
    int capacity;
public:
    vector(int sz, T value=T()) : size(sz),capacity(sz)
    {
        // buff = new T[sz];   // T의 default 생성자가 있어야 한다.
                            // 103 page에서 이렇게 하지 말라는 것이다.

        // 1. 메모리 먼저 할당
        buff = static_cast<T*>(operator new(sizeof(T) * size));

        // 2. 생성자 호출
        try
        {
            // buff ~ buff+10의 공간에 있는 객체에
            // value를 사용해서 복사 생성자 호출
            // cppreference.com에서 uninitialized_fill_n 함수 검색
            // #include <memory>
            //    Possible implementation을 보면 아래 코드와 같다.
            std::uninitialized_fill_n(buff,10,value);
        } catch(...){
            operator delete(buff);
        }
    }
};
int main()
{
    Point p(0,0);
    vector<Point> v(10,p);
}
```

------------

## traits
- #include <type_traits>

### specialization 이용한 traits 기능
- traits : 템플릿 인자 T의 다양한 특질(Traits)를 조사하는 기술.
    - speicialzation을 이용하여 <T*> 로 받을때는 enum {value=다른값}으로 정의하면된다.
    - ::으로 값을 가져오는 것은 enum과 변수 등 이다.
    - [partially_specialization.cpp 참조](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/partially_specialization.cpp)
- is_pointer : 컴파일할때 T가 pointer인지 조사하는 도구
    - 컴파일 할때 사용하는 함수 라는 의미로 meta function 이라고도 한다.
    - 만드는 방법
        - 1. 구조체 템플릿을 만든다.
        - 2. enum { value = false} 를 넣는다.
        - 3. 조건을 만족하는 부분 특수화 버전을 만든다. 그리고, eum {value = true}를 넣는다.
- [source 2_traits2 115 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/2_traits2.cpp)
```cpp
template<typename T> struct is_pointer
{
    enum {value = false };
};
// 템플릿 부분 특수화 (specialization) 문법
// T의 형태에 따라 다른 구현을 하겠다는 의미.
template<typename T> struct is_pointer<T*>
{
    enum {value = true };
};

template <typename T>
void foo(T v)
{
    if(is_pointer<T>::value){       // compile할때 처리한다. meta 함수라고도 한다.
        std::cout << "포인터 " << v << std::endl;
    } else {
        std::cout << "포인터 아님 " <<  v << std::endl;
    }
}
```

------------

### is_reference등..
- is_reference  ``` <T&> <T&&> ```
- is_const   ``` <const T> ```
- [source 2_traits3 115 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/2_traits3.cpp)

------------

### c++11 부터 다양한 traits를 표준으로 제공합니다.
```cpp
#include <type_traits>
    std::cout << is_reference<int>::value << std::endl; // 0
    std::cout << is_reference<int&>::value << std::endl; // 1

    std::cout << is_const<int>::value << std::endl; // 0
    std::cout << is_const<const int>::value << std::endl; // 1
```

------------

## int2type

### template
- 템플릿 : 클래스를 만드는 툴
    - 사용하지 않으면 클래스가 생성되지 않는다.
    - template은 사용한 코드만 만들어진다.
    - lazy instantiation : 사용된 템플릿만 인스턴스화 (실제 C++ code 생성) 된다.
- [source 3_int2type1  115 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/3_int2type1.cpp)
```cpp
template<typename T>
class A
{
    T data;
public:
    void foo(T a)
    {
        *a = 10;    // 1. 템플릿만 있을때는 코드가 안 만들어지므로 error가 나지 않는다.
    }

};

int main()
{
    A<int> a;       // 2. T는 지정은 했지만, foo를 호출하지 않았기 때문에 위의 1번 error가 발생하지 않는다.
    a.foo(0);       // 3. foo를 사용하므로 error가 발생한다.
}
```

- fail : https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/3_int2type2.cpp
```cpp
template<typename T>
void printv(T a)
{
    if(std::is_pointer<T>::value) // case 1 : if (false) <== compile에서 없어지지 않음.
        std::cout << a << ":" << *a << std::endl;
    else
        std::cout << a << std::endl;
}
```

- fail : https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/3_int2type3.cpp


------------

### int를 type으로 설정
- 0,1을 서로 다른 type으로 설정하기 위해서
    - 0,1은 일반적으로는 같은 int
- 템플릿 인자로는 "타입"뿐 아니라 "정수"를 보낼수도 있습니다 .
- [source 3_int2type5  115 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/3_int2type5.cpp)
```cpp
// 템플릿 인자로는 "타입"뿐 아니라 "정수"를 보낼수도 있습니다 .
template<int N> struct int2type     // 115 page
{
    enum { value = N};
};
int main()
{
    foo(0);
    foo(1); // 0,1은 같은 타입. foo(0)과 foo(1)은 동일한 함수를 호출
    int2type<0> t0;
    int2type<1> t1; // t0 , t1은 다른 type이다.
    foo(t0);
    foo(t1);    // t0,t1은 다른 type이므로 foo(t0)/foo(t1)은 다른 함수를 부른다.
}
```

------------

###  포인트  따라 구현부를 다르게 가져가는 함수 (int2type 이용 + 함수 overloading)
- [int2type4](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/3_int2type4.cpp) + [int2type5](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/3_int2type5.cpp)
-  함수 overloading을 사용한다.
    - foo(3.4) 이면 foo(int) / foo(double) 중에서 foo(double)로 간다.
        - template function이면서 overloading이 되게 해야 한다.
    - 함수는 같고 인수 type만 달라야 한다. 0,1의 값이 다른데 이것을 각기 다른 type으로 인지하게 해야 한다.
        - int2type을 이용하면 0,1이 서로 다른 type이 되므로 overloading이 가능해진다.
- [source 3_int2type6  115 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/3_int2type6.cpp)
```cpp
template<int N> struct int2type     // 115 page
{
    enum { value = N};
};

template<typename T> void printv_imp(T v,int2type<1>)   // type만 적어주어도 됨.
{
    std::cout << "pointer" << std::endl;
    std::cout << v << " : " << *v << std::endl;
}
template<typename T> void printv_imp(T v,int2type<0>)
{
    std::cout << "not pointer" << std::endl;
    std::cout << v << std::endl;
}
template<typename T>
void printv(T a)
{
    // T가 포인터인지에 따라 다른 함수를 호출하게 한다.
    printv_imp(a,int2type<std::is_pointer<T>::value>() );
            // int2type<0> ; 타입
            // int2type<0>() : 임시객체 **
}
```

------------

### integral_constant (int2type 발전 ; C++11 표준)
- 아래 int2type을 발전 (int , bool , short 등) 시켜서 C++11 표준에 추가됨.
    - integral_constant
```cpp
template<typename T,int N> struct integral_constant     // 115 page  : 시험문제
{
    enum { value = N};  // c++11 이전 스타일

    static constexpr T value = N ; // C++11 이후 스타일
                        // constexpr을 사용한 컴파일 시간 상수
};

integral_constant<int,0> t0;
integral_constant<int,1> t1;
integral_constant<short,1> s1;

integral_constant<bool,true> b0;
integral_constant<bool,false> b1;

// true/false : 참 ,거짓을 나타내는 값. 같은 타입
// true_type / false_type : 참, 거짓을 나타내는 값. 다른 타입
typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;
    // 객체는 임시로 true_type()  , false_type()


// C++ 표준의 is_pointer는 아래처럼 만들었습니다. (:기반클래스)
template<typename T> struct is_pointer : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};
```

- [source 3_int2type7  115 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/3_int2type7.cpp)
```cpp
#include <type_traits>
template<typename T> void printv_imp(T v,std::true_type)   // type만 적어주어도 됨.
{
    std::cout << "pointer" << std::endl;
    std::cout << v << " : " << *v << std::endl;
}
template<typename T> void printv_imp(T v,std::false_type)
{
    std::cout << "not pointer" << std::endl;
    std::cout << v << std::endl;
}
template<typename T>
void printv(T a)
{
    // T가 포인터인지에 따라 다른 함수를 호출하게 한다.
    printv_imp(a,std::is_pointer<T>() );
            // 클래스이름()  : 임시로 사용할 객체 생성
}
```

------------

### 포인터 여부에 따라 다르게 처리하는 방법 (3가지)  - Summary
- 포인터 여부에 따라 다르게 처리하는 방법 (3가지) 
    - C++17이전  -std=c++11
        - 1-1. (C++11) is_pointer<T>::value 사용
        - 1-2. (C++11) true_type/false_type을 사용한 함수 오버로딩
    - 2. enable_if  [뒷 단원에서 자세히..](https://github.com/cheoljoo/educated-advanced-cpp#enable_if)
    - C++17이후  -std=c++17
        - 3. if constexpr : 컴파일 시간 if 문

- 방법 1 (C++17 이전) : true_type/false_type을 사용한 함수 오버로딩
```cpp
tempate <typename T> void foo_imp(T v, true_type){}
tempate <typename T> void foo_imp(T v, false_type){}

template<typename T> void foo(T v)
{
    // 1. (C++11) is_pointer<T>::value 사용
    if(std::is_pointer<T>::value)
    {
        // 단 , 아래와 같은 표현식은 사용할수 없다.
        // *v = 10; // error
    } else {
    }

    // 2. (C++11) true_type/false_type을 사용한 함수 오버로딩
    //  foo_imp안에서는 *v=10 사용가능
    foo_imp(v, std::is_pointer<T>() );

}
```

- 방법 3. (C++17 이후) if constexpr : 컴파일 시간 if 문
```cpp
template<typename T> void foo(T v)
{
    // if constexpr : 컴파일 시간 if 문
    if constexpr (std::is_pointer<T>::value)
    {
        //*v = 10;
        std::cout << v << " : " << *v << std::endl;
    } else {
        std::cout << v << std::endl;
    }
}
```

- [source 3_int2type8  115 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/3_int2type8.cpp)


------------

## typename

### 템플릿 인자(T)에 의존된 타입을 사용할때는 반드시 앞에 typename을 붙여야 한다
- 클래스이름::???   -> ??? 자리에 올수 있는 것들
    - static 변수
    - enum 상수
    - typedef  : 이때는 type으로 보내는 것임.
- 컴파일러는 아래 한줄을 어떻게 해석해야 할까요?
    - (1) DWROD는 값 (static 변수 or enum 상수)이다.
    - (2) DWORD는 T안에 내포된 타입이다.   ==> **template이라고 앞에 붙여주어야함.**
- [source 4_typename](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/4_typename.cpp)
```cpp
    typename T::DWORD * p;  
    AAA::DWORD *p2;  // typename이 필요없다
                            // T가 아니라 명확한 이름(AAA)사용!
```

------------

## 평가되지 않는 표현식

### unevaluated expressio : 평가되지 않는 표현식 4개
- c++에서 평가되지 않는 표현식은 4개가 있다. (unevaluated expression)
    - sizeof(foo(0);    // 반환값의 크기
    - decltype(foo(0)); // 반환값의 타입
    - noexcept(foo(0);  // 함수가 예외가 있는지 조사
    - typeid(foo(0));   // 반환값의 타입 정보
- [source 5_unevaluated expression](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/5_notMeasuredExpr.cpp)
```cpp
    // sizeof안의 foo(0)은 호출되지 않는다.  ==> 평가되지 않는 표현식 
    std::cout << sizeof(foo(0))      << std::endl;  // 2  : return 값의 크기
```

------------

## SFINAE
- Substitution Failure Is Not An Error

### overloading resolution : 함수 찾는 순서 (float로 시작)
- overloading resolution : 함수 찾는 순서 (float로 시작)
    - 1. float : exactly matching - float
    - 2. template 를 사용해서 float 생성
    - 3. promotion (테이터 손실이 없는 변화) - double
    - 4. standard conversion (표준 타입까지 변환)
        - int , short가 있는 경우에는 어디로 갈지 모름 (compile error)
    - 5. 어떤 후보도 없을때 가변인자 사용
- [source 6_SFINAE1  215 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/6_SFINAE1.cpp)
```cpp
void foo(float n){ std::cout << "float" << std::endl; }     // 1
void foo(int n){ std::cout << "int" << std::endl; }         // 4
void foo(double n){ std::cout << "double" << std::endl; }   // 3
void foo(...){ std::cout << "..." << std::endl; }           // 5
template<typename T>  void foo(T n){ std::cout << "T" << std::endl; }             // 2

    //- overloading resolution : 함수 찾는 순서 (float로 시작)
    foo(f); 
```

------------

### 함수 호출시 어떤 함수를 호출하는지는 인자만 가지고 결정
- Substitution Failure Is Not An Error
- 핵심 1. 함수 호출시 어떤 함수를 호출하는지는 인자만 가지고 결정한다. 
    - 반환 타입은 관련 없다.
- Substitution Failure Is Not An Error
    - 템플릿을 사용하기로 결정하고 , T를 특정 타입으로 치환할때 실패하면 에러가 아니라 다른 버변의 함수를 사용하게 한다. 
- [source 6_SFINAE2  215 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/6_SFINAE2.cpp)
```cpp
template<typename T>
typename T::type foo(T n){ std::cout << "T" << std::endl; return 0;}
    // T와 같은 type으로 return하는데 , T가 들어간 type으로 선언하므로 typename을 붙여준다.
    // int::type foo(int n){} 함수를 생성하려고 한다.  그러나, int::type이라는 것은 없다. 

void foo(...){ std::cout << "..." << std::endl; }

    foo(10); 
```

------------

### SFINAE가 적용되는 위치 3곳 (함수 signature에 적용)
- SFINAE가 적용되는 위치 3곳 (함수 signature에 적용)
    - 1. 함수 반환값 : 가장 많이 사용되는 기술
        - ```template<typename T> typename T::type foo(T n){} ```
    - 2. 함수 인자 타입 : return type이 없는 2개중 하나인 생성자에 사용하고 싶을때
        - ```template<typename T> void foo(T n,typename T::type n2){} ```
    - 3. 템플릿 인자  : 함수의 모양이 복잡해지지 않는 특징이 있다.
        - ```template<typename T, typename T2 = typename T::type> void foo(T n) {} ```
- [source 6_SFINAE3  215 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/6_SFINAE3.cpp)


------------

## enable_if

### enable_if<A,B>
- enable_if<A,B>
    - A가 true이면 B를 그대로 , B가 없으면 void type 으로 반환
    - A가 false 이면 error
- [source 7_enable_if1   77 page ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/7_enableif1.cpp)
```cpp
template<bool b, typename T=void> struct enable_if
{
    typedef T type;
};

// 부분특수화에서는 default값을 적지 않아도 일반화의 적용을 받는다. 
template<typename T> struct enable_if<false,T>
{
};
```

------------

### 정수가 아닌 경우 실패하게 하고 싶다.static_assert / enable_if
- 정수가 아닌 경우 실패하게 하고 싶다.
    - static_assert : compile time에 assert하는 것임. 
        - 조건을 만족하지 못하면 무조건 error
    - enable_if : 조건을 만족하지 못하면 템플릿을 사용하지 않음
        - 동일 이름의 다른 함수가 있으면 사용가능
- https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h
```cpp
template<typename TYPE>
typename std::enable_if<traits<TYPE>::has_trivial_copy>::type  ==> 뒤의 인자가 없으므로 void
inline
copy_type(TYPE* d, const TYPE* s, size_t n) {
    memcpy(d,s,n*sizeof(TYPE));
}
```
- [source 7_enable_if2   77 page ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/7_enableif2.cpp)

- static_assert
```cpp
template<typename T> T gcd(T arg1 , T arg2)
{
    // arg1 , arg2 의 최대 공약수를 반환한다고 가정해 봅시다. 
    
    // 정수가 아닌 경우 실패하게 하고 싶다.
    // static_assert : 1번째 인자가 false이면 컴파일 중지
    static_assert(std::is_integral<T>::value,"not integral");
    return 0;
};
```

- enable_if
```cpp
template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
gcd(T arg1,T arg2)
{
    return 0;
}
```

------------

### type_traits : enable_if
- 아래의 내용은 [CGA_RDL](https://github.com/1434cga/CGA_RDL)로 정의되는 문법을 구현하는 template에서도 주로 사용하는 것이다.
    - template 의 의미를 가지면 어쩔 수 없나보당.  난 2000년 초에 쓴건데!!
- [source 7_enable_if3   77 page ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/7_enableif3.cpp)
```cpp
#include <type_traits>  // 이 안에 is_pointer등의 traits와 enable_if 있음.

// 포인터 일때만 사용할 템플릿
template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type         // void
printv(T v)
{
    std::cout << v << " : " << *v << std::endl;
}

// 포인터 아닐때만 사용할 템플릿
template<typename T>
typename std::enable_if<!std::is_pointer<T>::value>::type         // void
printv(T v)
{
    std::cout << v << std::endl;
}
```

------------

## printv : 타입에 따라 다른 print  (총정리)

### 방법 1. true_type / false_type을 사용하는 function overloading
- [source 9_printv1  ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/9_printv1.cpp)
```cpp
template<typename T> void printv_imp(T v,true_type)
{
    cout << v << " : " << *v << endl;
}
template<typename T> void printv_imp(T v,false_type)
{
    cout << v << endl;
}
template<typename T> void printv(T v)
{
    printv_imp(v,std::is_pointer<T>() ); // operator overloading
}
```

------------

### 방법 2. enable_if를 사용하는 방법
- [source 9_printv2  ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/9_printv2.cpp)
```cpp
template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type         // void
printv(T v)
{
    std::cout << v << " : " << *v << std::endl;
}
```

------------

### 방법 3. if constexprt - c++17 style
- cppreference.com 에서 INVOKE 찾아보세요.
    - possible implementation
- [source 9_printv3  ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/9_printv3.cpp)
```cpp
template<typename T> void printv(T v)
{
    if constexpr (is_pointer<T>::value)
        cout << v << " : " << *v << endl;
    else 
        cout << v << endl;

}
```

------------

## trivial 하다.
- trivial : 생성자 , 복사 생성자 , 소멸자 , 대입연산자 등이 하는 일이 없을 경우 'trivial하다' 라고 한다.

### trivial 조건
- trivial하려면
    - 1. 가상함수가 없고
    - 2. 객체형 멤버가 없거나 멤버의 생성자가 trivial하고
    - 3. 기반 클래스가 없거나 기반클래스의 생성자가 trivial하고
    - 4. 사용자가 만든 생성자가 없을때
- [source 10_trivial1](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/10_trivial1.cpp)


------------

### is_trivially_default_constructible
- C++11 ; 그러나 , g++ version에 따라 다르므로 -std=c++17 로 compile
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 10_trivial2](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/10_trivial2.cpp)
```cpp
    bool b = std::is_trivially_default_constructible<Test>::value;
```

------------

### 복사를 할때 얕은 / 깊은 복사중에서 선택하기 위해서  trivial한지를 조사한다.
- ```std::is_trivially_copy_constructible<T>::value```
- [source 10_trivial3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/10_trivial3.cpp)
    
- 구현 함수
```cpp
template <typename T>
void copy_type(T* d, T* s , size_t n)
{
    if(std::is_trivially_copy_constructible<T>::value){
        memcpy(d,s,sizeof(T)*n);    // 이것만 하면 얕은 복사
    } else {
        //  복사 생성자가 하는 일이 있으면 각 요소에 대해 복사 생성자 호출
        while(n--)
        {
            // new T;       // 메모리 할당 + 생성자 호출
            // new T(*s);   // 메모리 할당 + 복사 생성자 호출
            // new(d) T;    // d 메모리에 디폴트 생성자 호출
            new(d) T(*s);   // d 메모리에 복사 생성자 호출
            ++d, ++s;
        }
    }
}
```

- SNIFAE적용 (enable_if 이용)
```cpp
template <typename T>
typename std::enable_if<std::is_trivially_copy_constructible<T>::value>::type
copy_type(T* d, T* s , size_t n)
{
    memcpy(d,s,sizeof(T)*n);    // 이것만 하면 얕은 복사
}
template <typename T>
typename std::enable_if<!std::is_trivially_copy_constructible<T>::value>::type
copy_type(T* d, T* s , size_t n)
{
    //  복사 생성자가 하는 일이 있으면 각 요소에 대해 복사 생성자 호출
    while(n--)
    {
        // new T;       // 메모리 할당 + 생성자 호출
        // new T(*s);   // 메모리 할당 + 복사 생성자 호출
        // new(d) T;    // d 메모리에 디폴트 생성자 호출
        new(d) T(*s);   // d 메모리에 복사 생성자 호출
        ++d, ++s;
    }
}
```


------------

### atomic 가능성 check를 위한 trivial
- atomic을 만들려면 복사 생성자도 만들면 안되다. 그러므로 trivial 개념이 필요하다. 
- [source 10_trivial4](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/10_trivial4.cpp)


------------

## is_abstract

### std::is_abstract<>
- [source 11_is_abstract1](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/11_is_abstract1.cpp)
```cpp
    std::cout << std::is_abstract<Shape>::value << std::endl;
```

------------

### is_abstract의 구현
- 핵심 : 가변 인자보다 template 함수가 우선순위가 높다
    - 1. 함수 템플릿 버전과 가변인자 버젼의 2개의 함수를 함든다.
    - 2. 템플릿 버젼은 조건을 만족하지 않으면 실패하게 만든다.
- ```T arg``` : 추상클래스라면 실패. 하지만 인자를 보낼때 객체가 필요!
- ```T* arg``` : 추상클래스라도 포인터는 만들수 있다. 
- ```T (*arr)[2]``` :  **배열을 가리키는 포인터 - 추상 클래스는 배열을 가리키는 포인터를 만들수 없다.**
    - 배열에서는 크기가 있어야 하는데 , 추상은 크기를 구할수 없다. 
- [source 11_is_abstract2](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/11_is_abstract2.cpp)
```cpp
class Shape
{
public:
    virtual void Draw() = 0;
};

// 추상 클래스는 객체를 만들지 못한다. 
// return 값의 크기를 조사해보면 어떤게 불렸는지 알 수 있다.

//template<typename T> short test(T (*arr)[2]){}     // 추상클래스 일때 실패했으면 함
    // 아래줄 처럼 구현부를 뺌. 실제로 수행할 것은 아님.
template<typename T> short test(T (*arr)[2]);     // 추상클래스 일때 실패했으면 함
template<typename T> char test(...){}

    // 호출하지 말고 , 어느 함수가 호출되는지만 조사.
    int n = sizeof(test<Shape>(0));
```

------------

### is_abstract의 구현 (Generic)
- 잘 동작!
- [source 11_is_abstract4](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/11_is_abstract4.cpp)
```cpp
#include <iostream>
#include <type_traits>

class Shape
{
public:
    virtual void Draw() = 0;
};

// 어느 함수가 불리는지를 조사하는 것
template<typename T> struct is_abstract
{
    typedef char YES[1];        // 143 page ArrayOne
    typedef char NO[2];

    template<typename U> static NO& test(U (*arr)[2]);     // 추상클래스 일때 실패했으면 함
    template<typename U> static YES& test(...){}

    static constexpr bool value = (sizeof(test<T>(0)) == sizeof(YES));
};

int main()
{
    bool b = is_abstract<Shape>::value;
    std::cout << b << std::endl;
}
```

------------

## member detect

### 예제 : member detect
- **질문 : 결과 값이 1이 나와야 하는데 자꾸 0이 나옴.**  ```U() -> declval<U>()``` 으로만 바꾼 것이 4번
- [source 12_member_detect2 143 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/12_member_detect2.cpp)
- [source 12_member_detect4 143 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/12_member_detect4.cpp)

------------

### declval()
- ```Point& declval();```	 핵심 : 구현은 없습니다. 
    - ```template<typename T> T& declval();```
- [source 12_member_detect3 143 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/12_member_detect3.cpp)
```cpp
class Point
{
	int x, y;
public:
	//Point() {}
	Point(int a,int b):x(a),y(b) {}
	int foo() { return 0; }
};

	//int n = sizeof( Point().foo() );	// 4
		// default 생성자가 있다고 가정

	//int n = sizeof( declval().foo() );	// 4
	
	//int n = sizeof( declval<Point>().foo() );	// 4
	
	int n = sizeof( std::declval<Point>().foo() );	// 4
		// 평가되지 않는 표현식에서 함수의 사이즈를 알고 싶다면... 이것을 사용
```

------------

### 줄
- ```::*``` pointer to member function : https://www.codeguru.com/cpp/cpp/article.php/c17401/C-Tutorial-PointertoMember-Function.htm
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

