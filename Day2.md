

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
    - partially_specialization.cpp 참조
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
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------


### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### 줄
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------
