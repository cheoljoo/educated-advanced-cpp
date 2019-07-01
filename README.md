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
### 참조 계수 생성 규칙
- 규칙
    - 규칙 1 . 객체 생성시 참조 계수 증가
    - 규칙 2 . 포인터 복사시 참조계수 증가
    - 규칙 3 . 더이상 필요없을때 참조계수 감소
- Protectoed 소멸자 : 객체를 스택에 만들수 없게 한다.
    - 195 page 아래쪽 코드 : 객체를 heap에만 만들게 하거나 , stack에 못만들게 하는 방법
    - Car c; 와 같이 stack에서 부를때는 , 함수를 빠져나갈때 소멸자를 부르지만, protected에 선언된 소멸자는 call되지 않아서 에러가 발생한다.
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

    Car c;      // error : 위와 같이 protected일때 에러
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
- #include <atomic> 
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
