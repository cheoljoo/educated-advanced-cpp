# educated-advanced-cpp
- http://cafe.naver.com/cppmaster  =>  수업 종료후 수업에 사용한 소스 upload 예정
- 강석민 smkang@codenuri.co.kr

## 학습할 open source
- https://github.com/WebKit/webkit/blob/master/Source/WTF/wtf/RefCounted.h
```cpp
template<typename T> class RefCounted : public RefCountedBase {
    WTF_MAKE_NONCOPYABLE(RefCounted); WTF_MAKE_FAST_ALLOCATED;
public:
    void deref() const
    {
        if (derefBase())
            delete static_cast<const T*>(this);
    }

protected:
    RefCounted() { }
    ~RefCounted()
    {
    }
};
```
  - 왜 이렇게 상속 받아서 함수가 1개뿐일까?  그러나, 이건 공통된 테크닉이다.
  - C++에서 많이 사용하는 것에 이름을 붙임. C++ Idioms  라고 함.
  - protected로 하는 디자인은 ??   이다. (이름이 정해져있다)
- https://github.com/aosp-mirror/platform_system_core/tree/master/libcutils/include/RefBase.h
  - https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/RefBase.h
- https://github.com/bitcoin/bitcoin/blob/master/src/chain.h

- C++ 최신 기술 : https://isocpp.org/
  - 현재 C++의 상태 : https://isocpp.org/std/status
    - Modules이 c++20에서 영향이 큰데, include 대신 java처럼 import를 사용한다.  include는 컴파일시간이 많이 들어서 import로 바꾸자는 것임.
    - Concepts도 중요
    - Networking은 검증되었지만, 아직 들어오지는 않았음.

- visual c++ 2017/2019 : basic c++14     /std:c++17
- g++ 8.x/9.1 : basic c++14      -std=c++17

## Each Day Link
1. [Day1](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day1.md#day1)
1. [Day2](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2.md)
1. [Day3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3.md)
1. [Day4](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4.md)
1. [Day5](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5.md)

## g++ version
- C++11  -std=c++11
    - g++ (Ubuntu 4.8.5-2ubuntu1~14.04.1) 4.8.5
- C++17  -std=c++17   
    - g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0

## makefile
- Day 마다 makefile이 있습니다.  
- Day5에는 컴파일한 모든 내용이 들어있으니 참조하십시요.

--------

# Day1

## Casting
### const는 syntatical한 것으로 c=10 , *p=20으로 나온다.
- [source casting1](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/casting1.cpp)
```cpp
// casting1.cpp

#include <stdio.h>
#include <iostream>

int main()
{
    int n=5;
    //double* q = &n; // warning in C , but error in c++

    double* q = (double *) &n; // C style casting : ok. but it is dangerous.

    *q = 3.4;


    const int c=10; // this is syntactical.
    int *p=(int*)&c;
    *p = 20;  // so it is ok

    printf("%d\n",c);
    printf("%d\n",*p);
}
```

----------

### static_cast
    - 1. 연관성이 있는 타입끼리의 캐스팅 (reference가 아니다)
    - 2. 표준 타입을 값으로 캐스팅
    - 3. void* 를 다른 타입으로 캐스팅
- [source casting2](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/casting2.cpp)
```cpp
// casting2.cpp
        double d = 3.4;
        int n = static_cast<int>(d); // double => int  : ok

        //int *p1 = static_cast<int*>(&d);      // double *=>int* : error
        int *p2 = static_cast<int*>(malloc(100));  // void* => int* : ok
        const int c=10;
        int *p3 = static_cast<int*>(&c);        // const int* => int* : error
```

------------

### reinterpret_cast : memory 관련된 타입 캐스팅이 된다.  reference / point만 변환이 되는 것이다.
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source casting3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/casting3.cpp)
```cpp
    int n=10;
    double* p1 = static_cast<double*>(&n); // error
    double* p2 = reinterpret_cast<double*>(&n); // ok

    // 정수 => 포인터
    int* p3 = static_cast<int*>(10);    // error
    int* p4 = reinterpret_cast<int*>(10);   // ok

    // 참조
    char& r1 = static_cast<char&>(n); // error
    char& r2 = reinterpret_cast<char&>(n); // ok

    // 표준 타입의 값 형식 캐스팅
    double d1=n; // ok
    double d2 = reinterpret_cast<double>(n); //

// 상속과 캐스팅
struct A { int a ; };
struct B { int b ; };
struct C : public A , public B{ int c ; };

    C cc;
    A* pA=&cc;      // 1000
    B* pB = &cc;        // 1004
    B* pB1 = (B*)&cc;       // 1004
    B* pB2 = static_cast<B*>(&cc);  // 1004
        // cc의 주소에서 B를 찾아라.
        // B 가 없으면 에러, 있으면 B 주소 반환
        // compile할때 찾아라.
        // &cc + sizeof(A)

    B* pB3 = reinterpret_cast<B*>(&cc); // 1000
        // 단순 주소만 변환
        // cc의 주소를 무조건 B처럼 해석하겠다.  메모리의 재해석!
        // compile time 변환
    pB3->b=100;  // 결국 cc.a 에 넣게 됩니다.

    cout << & cc << endl;   // 1000
    cout << pA << endl;     // 1000
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

### const_cast : 
    - const_cast는 **const**와 **volatile**을 제거할때 사용하는 것이다.
    - const만 제거하는 것이고 , type을 바꾸지는 못한다.
- [source casting4](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/casting4.cpp)
```cpp
    const int c = 10 ;

    // 상수성을 제거하는 캐스팅
    int* p1 = static_cast<int*>(&c);    // error

    int* p2 = reinterpret_cast<int*>(&c);   // error
        // 서로 다른 타입의 포인터는 되는데 , 상수성을 제거 할수 없다.

    int* p3 = const_cast<int*>(&c);     // ok

    volatile int n=10;
    int* p4 = static_cast<int*>(&n);    // error

    int* p5 = const_cast<int*>(&n);     // ok
        // const_cast는 const와 volatile을 제거할때 사용하는 것이다.

    const int c = 10;

    // char* p = &c;  // error

    // c의 주소를 char*에 담아보세요
    char *p = reinterpret_cast<char*>(const_cast<int*>(&c));

    char* p1 = (char*)&c;  // ok .. C style casting
```

----------

## addressof
### 내주소를 알리지 말라!  ```Point* operator&() const { return nullptr; }```
    - 주소를 나타낼때는 0대신 nullptr을 사용하자 - c++11
- [source  1_addressof1.cpp  : 7 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/1_addressof1.cpp)
```cpp
class Point
{
    int x,y;
public:
    // 내 조소를 알지 말라 기법
    Point* operator&() const { return nullptr; }
};

    Point pt;
    Point* p = reinterpret_cast<Point*>(&pt);   // 이미 &을 불렀으므로 0
    //Point* p1 = &(reinterpret_cast<Point>(pt));   // error. 값 캐스팅

    Point* p1 = reinterpret_cast<Point*>( &(reinterpret_cast<char&>(pt)) ); // ok
        // char로 일반 변환해야 Point&로 먹지 않게 된다.  그래서 일단 char&으로 변환하여 다시 Point*으로 제변환하는 것이다.
```

-------------

### 최대의 경우인 const volatile로 바꾸어주고(const char) -> const없애고(char) -> 그것의 주소를 얻는다.
- [source  1_addressof3.cpp  : 7 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/1_addressof3.cpp)
```cpp
// 1_addressof3.cpp  : 7 page
#include <iostream>
using namespace std;

class Point
{
    int x,y;
public:
    Point(){x=0;y=0;}
    Point* operator&() const { return nullptr; }
};

template<typename T>
T* myaddressof(T& obj)
{
    //7 page 아래 소스 : 2번째 3번째 캐스팅 순서가 중요
    return reinterpret_cast<T*>(
            &(const_cast<char&>(        // const를 없앤다.
                reinterpret_cast<const volatile char&>(obj) )) ); // const를 계속 유지 , 없어도 추가
}
// error가 없도록 수정해라.
    const Point pt;
    const Point* p1 = myaddressof(pt);

    const Point* p2 = addressof(pt);
```

-------------

## 상수 멤버 함수
### **앞으로 const 붙이는 것을 꼭 해주세요.. 무지 중요합니다.**
- 핵심 : 상수 객체는 상수 함수만 호출 가능하다.
    - "객체의 상태를 변경하지 않는 모든 멤버 함수(getter)는 반드시 상수 멤버 함수되어야 한다."
    - ** 상수 객체는 member 함수를 부를수없다. 그러나, 함수 뒤에 const를 한 것을 부를수 있다. int getArea()뒤에 const가 없으면 에러가 된다.   header에는 꼭 const를 붙여주어야 한다.
```cpp
class Rect
{
    int x=0,y=0,w=10,h=10; // from c++11
public:
    int getArea() const     // 상수 멤버 함수 : 이 안에서 값을 변경하면 에러
    {         return w*h;       }
};

    const Rect r; // 생성자로 초기화 했다고 가정
    int n= r.getArea();
```
- [source 2_const1](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/2_const1.cpp)

-----------

## 참조 계수
- 규칙
    - 규칙 1 . 객체 생성시 참조 계수 증가
    - 규칙 2 . 포인터 복사시 참조계수 증가
    - 규칙 3 . 더이상 필요없을때 참조계수 감소
    
### Prohibiting heap-based objects
- heap은 new operatior를 사용하므로 , new operator를 protected안에 넣으면 된다.
```cpp
protected:
    static void* operator new(std::size_t);
    static void* operator new [](std::size_t);
```

### Requiring heap-based objects
- Protectoed 소멸자 : 객체를 스택에 만들수 없게 한다.
    - 195 page 아래쪽 코드 : 객체를 heap에만 만들게 하거나 , stack에 못만들게 하는 방법
    - Car c; 와 같이 stack에서 부를때는 , 함수를 빠져나갈때 소멸자를 부르지만, protected에 선언된 소멸자는 call되지 않아서 에러가 발생한다.
- constructor의 경우는 private/protected 모두 heap-based에서도 접근할수 없다. destructor는 단지 heapOnly delete가 가능하다. 
- [source 3_reference2 : 195 page  ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/3_reference2.cpp)
```cpp
// 3_참조계수2.cpp
// delete를 할 시점을 잡는게 힘들다.
//
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Car
{
    int m_refCount = 0 ; // 참조계수를 위한 변수        // c++11부터 member field 초기화 가능
public:
    void ref() { ++m_refCount; }
    void deref(){ if(--m_refCount == 0) delete this; }

    // Protectoed 소멸자 : 객체를 스택에 만들수 없게 한다.
    //      195 page 아래쪽 코드 : 객체를 heap에만 만들게 하거나 , stack에 못만들게 하는 방법
    //  Car c; 와 같이 stack에서 부를때는 , 함수를 빠져나갈때 소멸자를 부르지만, call되지 않아서 에러가 발생한다.
protected :
    ~Car() { cout << "~Car" << endl; }
};

    Car c;      // error : 위와 같이 protected일때 에러 (stack에 선언되므로)
```

-----------

### 파생클래스의 소멸자 호출
- 핵심 기반 클래스 포인터로 delete하면 기반 클래스의 소멸자만 호출된다.
    - 파생클래스 소멸자를 호출되게 하려면 viraul destructor를 사용해야 한다. - C++ 기본 문법
    - **virtual** ~myRefCountedBase(){}
- [source 3_reference3 : 195 page  ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/3_reference3.cpp)

-----------

### virtual을 사용하지 않고 파생클래스의 소멸자 호출
- virtual을 사용하면 실행 속도가 느려질수 있어 , 가능하면 사용하지 않으려 한다.
- CRTP (Curiosly Recurring Templae Pattern) - 71 page
    - // 기반 클래스가 템플릿인데, 파생 클래스를 만들때 자신의 이름을
    - // 템플릿 인자로 전달해주는 기술.
    - // 미래에 만들어질 파생클래스의 이름을 미리 사용할수 있다.
    - // ex) 가상 함수를 사라지게 하다.   속도도 느리지 않고 , (virtual 사용하지 않음)
- [source 3_reference4 : 71 page : CRTP  ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/3_reference4.cpp)
```cpp
template <typename T>
class myRefCountedBase
{
    int m_refCount = 0 ;
public:
    void ref() { ++m_refCount; }
    void deref()    // void deref( myRefCountedBase* this)
    {
        if(--m_refCount == 0)
            //delete static_cast<Car*>(this);       // 이런 경우 Car를 모르므로 error
                    // 그래서 template으로 변환
            delete static_cast<T*>(this);   // ok
    }
protected:
    ~myRefCountedBase(){}
};

class Car : public myRefCountedBase<Car>
{
public:
    ~Car() { cout << "~Car" << endl; }
};
int main()
{
    Car* p1 = new Car;
    p1->ref();  // 규칙 1 . 객체 생성시 참조 계수 증가

    Car* p2 = p1;
    p2->ref();  // 규칙 2 . 포인터 복사시 참조계수 증가

    p2->deref();    // 규칙 3 . 더이상 필요없을때 참조계수 감소
    p1->deref();    // 규칙 3 . 더이상 필요없을때 참조계수 감소

}
```

----------

### 참조 계수를 조작하는 함수
- 상수 객체라도 수명을 관리할수 있어야 한다.
- 참조 계수를 조작하는 함수는 반드시 "상수 멤버함수"이어야 한다.
    - 참조 계수 변수에 mutable을 붙여서 const에서도 write가 되게 해야 한다.
- [source 3_reference5](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/3_reference5.cpp)
```cpp
template <typename T>
class myRefCountedBase
{
    mutable int m_refCount = 0 ;
public:
    // 상수 객체라도 수명을 관리할수 있어야 한다.
    // 참조 계수를 조작하는 함수는 반드시 "상수 멤버함수"이어야 한다.
    void ref() const { ++m_refCount; }
    void deref() const  // void deref( myRefCountedBase* this)
    {
        if(--m_refCount == 0)
            delete static_cast<T*>(this);
    }
protected:
    ~myRefCountedBase(){}
};
```

---------

### C++11 멀티쓰레드에서 안전한 타입 (atomic)
- ```#include <atomic> ```
- fetch가 CPU lock을 쓰므로 성능적으로 더 유리하다. mutex lock은 보통 system lock을 사용하게 된다.
- this in ```void deref() const```
    - 일반 멤버 함수에서 this : RefCountedBase* this
    - 상수 멤버 함수에서 this : const RefCountedBase* this
- 구글 " android github" :  https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/LightRefBase.h
- [source 3_reference6](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/3_reference6.cpp)
```cpp
templae<typename T>
class RefCountedBase
{
    mutable std::atomic<int> m_refCount = 0;
public:
    void ref() const
    {
        m_refCount.fetch_add(1);
    }
    void deref() const
    {
        m_refCount.fetch_sub(1);
            // fetch가 CPU lock을 쓰므로 성능적으로 더 유리하다.
        int cnt = m_refCount.load();
        if(cnt == 0){
            delete static_cast<const T*>(this); // ok : 이 모양도 가능하다. this가 const이니 맞춰준다. const T*도 delete가 된다.
        }
    }
protected:
    ~RefCountedBase() {}
};
```

------------

### thin template
- 클래스 템플릿이 너무 많은 타입에 대해서 인스턴스화 될때 코드가 커닐수 있다. - code bloat
    - // code bloat를 막기 위한 기술
- T를 사용하지 않는 멤버 함수를 템플릿이 아닌 기반 클래스를 만들어서 상속받자.!!
- 클래스 템플릿을 만들때 템플릿 파라미터 T를 사용하지 않는 멤버 함수는  (여기서는 이게 많을수 있기에 code memory절약을 위해서) 템플릿이 아닌 기반 클래스를 만들어서 상속 받자 
    - class RefCountedBase
- [source 3_reference7](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/3_reference7.cpp)
```cpp
class RefCountedBase
{
protected:
        mutable int m_refCount = 0 ;
public:
        void ref() const { ++m_refCount; }
};

template <typename T>
class RefCounted : public RefCountedBase
{
public:
        void deref() const      // void deref( const RefCounted* this)
        {
            if(--m_refCount == 0){
                delete static_cast<T*>(
                        const_cast<RefCounted*>(this));
            }
        }
protected:
        ~RefCounted(){}
};
class Car : public RefCounted<Car>
{
public:
        ~Car() { std::cout << "~Car" << std::endl; }
};
        const Car* p1 = new Car;
```

------------

### 복사되면 안되는 class (MACRO) : 참조 계수 class를 복사되지 않게 해야 한다. 
- 이 클래스는 (또는 기반 클래스)는 복사 되면 안된다.
    - // 컴파일러가 복사 생성자를 만들지 못하게 된다.
    - // 아래 2개는 항상 쌍으로 다닌다.  그래서 macro를 이용한다.
    - ```RefCounted(const RefCounted&) = delete; // c++11 함수 삭제```
    - ```RefCounted& operator=(const RefCounted&) = delete;  // 대입도 삭제```
- 항상 사용하는 복사 생성자 쌍을 MACRO를 사용하여 처리한다.
- [source 3_reference8](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/3_reference8.cpp)
```cpp
#define WTF_MAKE_NONCOPYABLE(classname) \
    classname(const classname&) = delete; \
    classname& operator=(const classname&) = delete;
template <typename T>
class RefCounted : public RefCountedBase
{
    //RefCounted(const RefCounted&) = delete; // c++11 함수 삭제
    //RefCounted& operator=(const RefCounted&) = delete;  // 대입도 삭제
    WTF_MAKE_NONCOPYABLE(RefCounted);
```

------------

### 스마트 포인터
- 객체를 참조 계수 기반으로 관리하기로 결정했다면 raw pointer를 사용하게 하지 말자!! 스마트 포인터를 도입해야 한다.
- 진짜 포인터처럼 -> 를 사용할수 있어야 한다.
```cpp
    T* operator->() { return m_obj; }
    T& operator*() { return *m_obj; }
```
- [source 3_reference10](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/3_reference10.cpp)
```cpp
template<typename T> class AutoPtr
{
    T* m_obj;
public:
    AutoPtr(T* p=0):m_obj(p)
    {
        if(m_obj) m_obj->ref();
    }
    AutoPtr(const AutoPtr& p):m_obj(p.m_obj)
    {
        if(m_obj) m_obj->ref();
    }
    ~AutoPtr()
    {
        if(m_obj) m_obj->deref();
    }
    T* operator->() { return m_obj; }
    T& operator*() { return *m_obj; }
};

int main()
{
    // 진짜 포인터처럼 AutoPtr를 사용하면 됩니다.
    AutoPtr<Car> p1 = new Car;      // AutoPtr<Car> p1(new Car)
    p1->Go();       // p1.operator->()의 원리 입니다.
    AutoPtr<Car> p2 = p1;


    // webkit에서는 AutoPtr로 참조 계수를 관리한다.
}
```

------

## thin template
### template는 너무 많은 member 함수를 만든다.
- 템플릿 인자와 관련 없는 모든 멤버는 기반 클래스(템플린이 아닌)로 제공한다.
- [source 4_thinTemplate3 : 237 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/4_thinTemplate3.cpp)
```cpp
// 템플릿 인자와 관련 없는 모든 멤버는 기반 클래스(템플린이 아닌)로 제공한다.
class VectorBase
{
protected:
    int size;
public:
    VectorBase(int sz):size(sz){}
    int getSize() const { return size; }
};

// 2개의 타입에 대해 vector사용 => 총 10개의 member함수가 생성됨.
template<typename T>
class Vector : public VectorBase
{
    T* buff;
public:
    Vector(int sz):VectorBase(sz) { buff = new T[size]; }
    ~Vector() { delete[] buff; }

    T& front() { return buff[0]; }
    T& last(){ return buff[size-1]; }
};
```

----------------

### void를 이용하여 thin template을 더 가볍게
- pointer에 대해서는 ```void*```를 사용하면 더 많은 member function을 Base class에 넣울수 있다.
    - 실제로는 T 를 쓰는 것들의 크기가 크다.
    - 이번에는 T도 VectorBase로 올려본다.
    - void* 기반 컨테이너 and template에서는 casting만 책임진다.
- shared_ptr와 AutoPtr 비교
```
    - // shared_ptr<int> sp(new int) : ok
    - //   참조계수를 스마트 포인터가 관리
    - //   make_shared를 이용해서 객체과 참조계수 객체를 같이 붙여서 memory fragmentation을 방지 할수 있다.
    - //   overhead는 2배의 overhaed
    - // AutoPtr<int> sp(new int): error
    - //   AutoPtr<int> sp(new Car): ok
    - //   참조 계수를 객체가 관리한다.
```
- android 소스에서 platform_system_core/libutils/include/Vector.h 열어보세요.  VectorImpl
    - android에서는 Vector같은 것들 표준에 있는 것을 std를 사용하도록 권장한다.
- [source 4_thinTemplate4 : 237 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/4_thinTemplate4.cpp)
```cpp
class VectorBase
{
protected:
    int size;
    void** buff;
public:
    VectorBase(int sz):size(sz)
    {
        buff = new void*[size];
    }
    ~VectorBase()
    {
        delete[] buff;
    }
    void* front() { return buff[0]; }
    void* last() { return buff[size-1]; }
    int getSize() const { return size; }
};

// template에서는 casting만을 하고 ( compile time)
// 이것은 code memory가 확 줄어든다.
template<typename T>
class Vector : public VectorBase
{
    T* buff;
public:
    Vector(int sz):VectorBase(sz) { }

    T& front() { return static_cast<T&>(buff[0]); }
    T& last(){ return static_cast<T&>(buff[size-1]); }
};
```

----------

## this
- this 에 대한 설명
    - 함수가 const이면 arguments들도 모두 const가 붙어서 넘겨지게 된다. this 도 마찬가지이다.
- [source 5_this](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/5_this1.cpp)
```cpp
class Point
{
    int x,y;
public:
    void set(int a, int b)      // set(Point* this,int a, int b)
    {
        x=a;    // this->x =a;
        y=b;    // this->y =b;
    }
    void print() const  // print (const Point* this)
    {
        x=10;           // error : const this->x=10 이 안되기 때문이다.
    }
};

int main()
{
    Point p1,p2;
    p1.set(10,20);  // set(&p1,10,20)의 의미로 전달됩니다.
                    // push 20
                    // psuh 10      진짜 인자는 스택으로
                    // mov ecx,&p1   객체 주소는 레지스터에
                    // call Point::set
}
```

----------

## CRTP
-  virtual로 call 하면 MyWindow::Click를 부를수 있다. 그러나, 느려지므로 virtual은 쓰지 않는 것으로 한다. 그래서 template을 대신 사용
- android ::  libutils/include/utils/singleton.h  : CRTP를 사용하는 singleton    but , 여기서도 다른 방식 추천
- [source 6_CRTP](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/6_CRTP1.cpp)
```cpp
// MS오픈소스인 WTL(Window Template Library) 라이브러리가 이벤트를 처리하는 방식
template <typename T>
class Window
{
public:
    void msgLoop()  // msgLoop(Window* this)
    {
        //Click();    // this->Click()
        static_cast<T*>(this)->Click();
    }
    void Click() {
        std::cout << "Window::Click" << std::endl;  // 1
    }
};
class MyWindow : public Window<MyWindow>
{
public:
    void Click(){ std::cout << "MyWindow::Click" << std::endl; }  // 2
};


int main()
{
    MyWindow w;
    w.msgLoop();    // 1을 call

}
```

-----------

## 예외 안정성
- // 예외 안정성 (exception safety)
    - 1. 완전 보장 : 예외가 없다. ex) int n=0  int *p = nullptr
    - 2. 강력 보장 : 예외가 있지만 잡아서 처리하면 객체의 상태는 예외 발생 이전 상태가 된다. 계속 사용가능하다.
    - 3. 기본 보장 : 예외가 발생해도 잡으면 자원 누수는 없다.  단, 객체의 상태는 알수 없다. 이어서 사용할수 없다.
### 제거와 반환을 분리
- stl은 제거와 반환을 분리  : 강력 보장을 지키기 위해서 이다.
- STL이 제거와 반환을 동시에 하지 않는 이유
    - 1. 예외 안정성의 강력보장을 지키기 위해
    - 2. 참조 반환을 통해서 임시객체를 제거하기 위해서
- [source 7_safe2](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/7_safe2.cpp)
```cpp
template <typename T>
class Stack
{
    T buff[10];
    int idx=-1;
public:
    void push(const T& a){ buff[++idx] = a; }

    // 제거와 반환을 동시에 하면 강력 보장을 지킬수 없다.
    // 제거와 반환은 분리한다.
    T& top() { return buff[idx]; }  // 반환만
    void pop() { --idx; } // 제거만
};

class People {};

int main()
{
    Stack<People> s;
    People p;
    s.push(p);
    try
    {
        People p = s.top(); // 꺼내기만
        s.pop(); // 제거만
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
```

-----------

### 깊은 복사로 구현한 대입 연산자 : copy-and-swap
- 자신과 대입할 경우 (s1 = s1) ```        if(&s == this) return *this;```
- s의 복사본을 만든다. ```   String temp(s);     // RAII 기법```
    - RAII 기법: 중간에 문제가 되어도 String은 객체이므로 관련 내용은 소멸이 잘 되어 문제가 안된다.
- s의 버포와 자산의 버퍼를 교체한다.

- [source 7_safe3 : 59 page ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/7_safe3.cpp)
```cpp
class String
{
    char* buff;
public:
    // 이것은 얕은 복사가 되어서 , s1=s2를 하면 주소만 copy되는 것이다.
    String(const char* s)
    {
        buff = new char[strlen(s)+1];
        strcpy(buff,s);
    }
    ~String(){ delete[] buff; }

    String(const String& s)
    {
        buff = new char[strlen(s.buff)+1];      // 여기서 fail이 나면 그 이후는 수행을 하지 않는다. 그러나, 나는 안전한다.
        strcpy(buff,s.buff);
    }
    void swap(String& s)
    {
        char* temp = s.buff;
        s.buff = buff;
        buff = temp;
    }

    // 깊은 복사로 구현한 대입 연산자
    // ** exception safety를 아는 사람들은 대입을 해도 이렇게 짜야 한다.  **
    String& operator=(const String& s)
    {
        // 자신과 대입할 경우 (s1 = s1)
        if(&s == this) return *this;

        // s의 복사본을 만든다.
        String temp(s);     // RAII 기법 : 중간에 문제가 되어도 String은 객체이므로 관련 내용은 소멸이 잘 되어 문제가 안된다.
        // s의 버포와 자산의 버퍼를 교체한다.
        temp.swap(*this);

        return *this;
    }
};

int main()
{
    String s1 = "hello";
    String s2 = "AAA";

    s1 = s2; //  이때를 생각해 봅시다.
}
```

--------

