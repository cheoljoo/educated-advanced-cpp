1\.  [educated-advanced-cpp](#educated-advanced-cpp)  
1.1\.  [학습할 open source](#학습할opensource)  
1.2\.  [Each Day Link](#eachdaylink)  
2\.  [Day1](#day1)  
2.1\.  [Casting](#casting)  
2.1.1\.  [const는 syntatical한 것으로 c=10 , *p=20으로 나온다.](#const는syntatical한것으로c=10*p=20으로나온다.)  
2.1.2\.  [static_cast](#static_cast)  
2.1.3\.  [reinterpret_cast : memory 관련된 타입 캐스팅이 된다.  reference / point만 변환이 되는 것이다.](#reinterpret_cast:memory관련된타입캐스팅이된다.reference/point만변환이되는것이다.)  
2.1.4\.  [const_cast :](#const_cast:)  
2.2\.  [addressof](#addressof)  
2.2.1\.  [내주소를 알리지 말라!  ```Point* operator&() const { return nullptr; }```](#내주소를알리지말라!```point*operator&const{returnnullptr;}```)  
2.2.2\.  [최대의 경우인 const volatile로 바꾸어주고(const char) -> const없애고(char) -> 그것의 주소를 얻는다.](#최대의경우인constvolatile로바꾸어주고constchar->const없애고char->그것의주소를얻는다.)  
2.3\.  [상수 멤버 함수](#상수멤버함수)  
2.3.1\.  [**앞으로 const 붙이는 것을 꼭 해주세요.. 무지 중요합니다.**](#**앞으로const붙이는것을꼭해주세요..무지중요합니다.**)  
2.4\.  [참조 계수](#참조계수)  
2.4.1\.  [Prohibiting heap-based objects](#prohibitingheap-basedobjects)  
2.4.2\.  [Requiring heap-based objects](#requiringheap-basedobjects)  
2.4.3\.  [파생클래스의 소멸자 호출](#파생클래스의소멸자호출)  
2.4.4\.  [virtual을 사용하지 않고 파생클래스의 소멸자 호출](#virtual을사용하지않고파생클래스의소멸자호출)  
2.4.5\.  [참조 계수를 조작하는 함수](#참조계수를조작하는함수)  
2.4.6\.  [C++11 멀티쓰레드에서 안전한 타입 (atomic)](#c++11멀티쓰레드에서안전한타입atomic)  
2.4.7\.  [thin template](#thintemplate)  
2.4.8\.  [복사되면 안되는 class (MACRO) : 참조 계수 class를 복사되지 않게 해야 한다.](#복사되면안되는classmacro:참조계수class를복사되지않게해야한다.)  
2.4.9\.  [스마트 포인터](#스마트포인터)  
2.5\.  [thin template](#thintemplate-1)  
2.5.1\.  [template는 너무 많은 member 함수를 만든다.](#template는너무많은member함수를만든다.)  
2.5.2\.  [void를 이용하여 thin template을 더 가볍게](#void를이용하여thintemplate을더가볍게)  
2.6\.  [this](#this)  
2.7\.  [CRTP](#crtp)  
2.8\.  [예외 안정성](#예외안정성)  
2.8.1\.  [제거와 반환을 분리](#제거와반환을분리)  
2.8.2\.  [깊은 복사로 구현한 대입 연산자 : copy-and-swap](#깊은복사로구현한대입연산자:copy-and-swap)  
3\.  [Day2](#day2)  
3.1\.  [new](#new)  
3.1.1\.  [메모리 할당과 생성자 분리](#메모리할당과생성자분리)  
3.1.2\.  [0,0으로 초기화된 Point를 힙에 10개 만들자.](#00으로초기화된point를힙에10개만들자.)  
3.1.3\.  [vector의 메모리 관리 기술](#vector의메모리관리기술)  
3.1.4\.  [vector resize](#vectorresize)  
3.1.5\.  [vector를 만들어보자](#vector를만들어보자)  
3.2\.  [### 많이 사용하는 try catch를 std에서 제공하는 함수로 대치](####많이사용하는trycatch를std에서제공하는함수로대치)  
3.3\.  [traits](#traits)  
3.3.1\.  [specialization 이용한 traits 기능](#specialization이용한traits기능)  
3.3.2\.  [is_reference등..](#is_reference등..)  
3.3.3\.  [c++11 부터 다양한 traits를 표준으로 제공합니다.](#c++11부터다양한traits를표준으로제공합니다.)  
3.4\.  [int2type](#int2type)  
3.4.1\.  [template](#template)  
3.4.2\.  [int를 type으로 설정](#int를type으로설정)  
3.4.3\.  [포인트  따라 구현부를 다르게 가져가는 함수 (int2type 이용 + 함수 overloading)](#포인트따라구현부를다르게가져가는함수int2type이용+함수overloading)  
3.4.4\.  [integral_constant (int2type 발전 ; C++11 표준)](#integral_constantint2type발전;c++11표준)  
3.4.5\.  [포인터 여부에 따라 다르게 처리하는 방법 (3가지)  - Summary](#포인터여부에따라다르게처리하는방법3가지-summary)  
3.5\.  [typename](#typename)  
3.5.1\.  [템플릿 인자(T)에 의존된 타입을 사용할때는 반드시 앞에 typename을 붙여야 한다](#템플릿인자t에의존된타입을사용할때는반드시앞에typename을붙여야한다)  
3.6\.  [평가되지 않는 표현식](#평가되지않는표현식)  
3.6.1\.  [unevaluated expressio : 평가되지 않는 표현식 4개](#unevaluatedexpressio:평가되지않는표현식4개)  
3.7\.  [SFINAE](#sfinae)  
3.7.1\.  [overloading resolution : 함수 찾는 순서 (float로 시작)](#overloadingresolution:함수찾는순서float로시작)  
3.7.2\.  [함수 호출시 어떤 함수를 호출하는지는 인자만 가지고 결정](#함수호출시어떤함수를호출하는지는인자만가지고결정)  
3.7.3\.  [SFINAE가 적용되는 위치 3곳 (함수 signature에 적용)](#sfinae가적용되는위치3곳함수signature에적용)  
3.8\.  [enable_if](#enable_if)  
3.8.1\.  [enable_if<A,B>](#enable_if<ab>)  
3.8.2\.  [정수가 아닌 경우 실패하게 하고 싶다.static_assert / enable_if](#정수가아닌경우실패하게하고싶다.static_assert/enable_if)  
3.8.3\.  [type_traits : enable_if](#type_traits:enable_if)  
3.9\.  [printv : 타입에 따라 다른 print  (총정리)](#printv:타입에따라다른print총정리)  
3.9.1\.  [방법 1. true_type / false_type을 사용하는 function overloading](#방법1.true_type/false_type을사용하는functionoverloading)  
3.9.2\.  [방법 2. enable_if를 사용하는 방법](#방법2.enable_if를사용하는방법)  
3.9.3\.  [방법 3. if constexprt - c++17 style](#방법3.ifconstexprt-c++17style)  
3.10\.  [trivial 하다.](#trivial하다.)  
3.10.1\.  [trivial 조건](#trivial조건)  
3.10.2\.  [is_trivially_default_constructible](#is_trivially_default_constructible)  
3.10.3\.  [복사를 할때 얕은 / 깊은 복사중에서 선택하기 위해서  trivial한지를 조사한다.](#복사를할때얕은/깊은복사중에서선택하기위해서trivial한지를조사한다.)  
3.10.4\.  [atomic 가능성 check를 위한 trivial](#atomic가능성check를위한trivial)  
3.11\.  [is_abstract](#is_abstract)  
3.11.1\.  [std::is_abstract<>](#std::is_abstract<>)  
3.11.2\.  [is_abstract의 구현](#is_abstract의구현)  
3.11.3\.  [is_abstract의 구현 (Generic)](#is_abstract의구현generic)  
3.12\.  [member detect](#memberdetect)  
3.12.1\.  [예제 : member detect](#예제:memberdetect)  
3.12.2\.  [declval()](#declval)  
4\.  [Day3](#day3)  
4.1\.  [pointer of member function](#pointerofmemberfunction)  
4.1.1\.  [pointer of member function and invoke (c++17)](#pointerofmemberfunctionandinvokec++17)  
4.1.2\.  [class안의 static 함수의 특징 (Thread)](#class안의static함수의특징thread)  
4.1.3\.  [std::enable_shared_from_this](#std::enable_shared_from_this)  
4.1.4\.  [모든 함수 pointer를 담을수 있는 pointer](#모든함수pointer를담을수있는pointer)  
4.1.5\.  [object Generator 라는 기술 : makeAction makePair](#objectgenerator라는기술:makeactionmakepair)  
4.1.6\.  [deduction](#deduction)  
4.2\.  [smart pointer](#smartpointer)  
4.2.1\.  [smart pointer 사용처](#smartpointer사용처)  
4.2.2\.  [smart pointer 객체 + 관리객체 및 make_shared](#smartpointer객체+관리객체및make_shared)  
4.2.3\.  [관리 객체가 가지는 4가지](#관리객체가가지는4가지)  
4.2.4\.  [weak_pointer](#weak_pointer)  
4.3\.  [forwarding reference](#forwardingreference)  
4.3.1\.  [lvalue rvalue](#lvaluervalue)  
4.3.2\.  [인자 type에 다른 함수 우선 순위](#인자type에다른함수우선순위)  
4.3.3\.  [reference collapsing : 레퍼런스 붕괴](#referencecollapsing:레퍼런스붕괴)  
4.3.4\.  [typename T를 고려한 lvalue rvalue](#typenamet를고려한lvaluervalue)  
4.3.5\.  [lvalue와 rvalue를 모두 전달받는 함수 만들기](#lvalue와rvalue를모두전달받는함수만들기)  
4.3.6\.  [2개의 함수를 이용한 함수 전부 받아주기 방식 구현](#2개의함수를이용한함수전부받아주기방식구현)  
4.3.7\.  [template으로 변환을 하자](#template으로변환을하자)  
4.3.8\.  [example: make_shared](#example:make_shared)  
4.3.9\.  [forwarding reference](#forwardingreference-1)  
4.3.10\.  [생성자 모양](#생성자모양)  
4.3.11\.  [forwarding reference 기본 template](#forwardingreference기본template)  
4.3.12\.  [lvalue rvalue를 위한 member 함수 선언](#lvaluervalue를위한member함수선언)  
4.4\.  [const](#const)  
4.4.1\.  [const 의 위치에 따른 의미](#const의위치에따른의미)  
4.5\.  [temporary : 임시객체](#temporary:임시객체)  
4.5.1\.  [객체의 종류](#객체의종류)  
4.5.2\.  [임시객체의 특징](#임시객체의특징)  
4.5.3\.  [임시객체 사용예](#임시객체사용예)  
4.5.4\.  [return by value](#returnbyvalue)  
4.5.5\.  [참조 캐스팅](#참조캐스팅)  
4.5.6\.  [복사 생성자 모양](#복사생성자모양)  

<a name="educated-advanced-cpp"></a>

# 1\. educated-advanced-cpp
- http://cafe.naver.com/cppmaster  =>  수업 종료후 수업에 사용한 소스 upload 예정
- 강석민 smkang@codenuri.co.kr

<a name="학습할opensource"></a>

## 1.1\. 학습할 open source
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

<a name="eachdaylink"></a>

## 1.2\. Each Day Link
1. [Day1](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day1.md#day1)
1. [Day2](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2.md)
1. [Day3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3.md)
1. [Day4](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4.md)
1. [Day5](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5.md)


--------

<a name="day1"></a>

# 2\. Day1

<a name="casting"></a>

## 2.1\. Casting
<a name="const는syntatical한것으로c=10*p=20으로나온다."></a>

### 2.1.1\. const는 syntatical한 것으로 c=10 , *p=20으로 나온다.
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

<a name="static_cast"></a>

### 2.1.2\. static_cast
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

<a name="reinterpret_cast:memory관련된타입캐스팅이된다.reference/point만변환이되는것이다."></a>

### 2.1.3\. reinterpret_cast : memory 관련된 타입 캐스팅이 된다.  reference / point만 변환이 되는 것이다.
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

<a name="const_cast:"></a>

### 2.1.4\. const_cast : 
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

<a name="addressof"></a>

## 2.2\. addressof
<a name="내주소를알리지말라!```point*operator&const{returnnullptr;}```"></a>

### 2.2.1\. 내주소를 알리지 말라!  ```Point* operator&() const { return nullptr; }```
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

<a name="최대의경우인constvolatile로바꾸어주고constchar->const없애고char->그것의주소를얻는다."></a>

### 2.2.2\. 최대의 경우인 const volatile로 바꾸어주고(const char) -> const없애고(char) -> 그것의 주소를 얻는다.
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

<a name="상수멤버함수"></a>

## 2.3\. 상수 멤버 함수
<a name="**앞으로const붙이는것을꼭해주세요..무지중요합니다.**"></a>

### 2.3.1\. **앞으로 const 붙이는 것을 꼭 해주세요.. 무지 중요합니다.**
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

<a name="참조계수"></a>

## 2.4\. 참조 계수
- 규칙
    - 규칙 1 . 객체 생성시 참조 계수 증가
    - 규칙 2 . 포인터 복사시 참조계수 증가
    - 규칙 3 . 더이상 필요없을때 참조계수 감소
    
<a name="prohibitingheap-basedobjects"></a>

### 2.4.1\. Prohibiting heap-based objects
- heap은 new operatior를 사용하므로 , new operator를 protected안에 넣으면 된다.
```cpp
protected:
    static void* operator new(std::size_t);
    static void* operator new [](std::size_t);
```

<a name="requiringheap-basedobjects"></a>

### 2.4.2\. Requiring heap-based objects
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

<a name="파생클래스의소멸자호출"></a>

### 2.4.3\. 파생클래스의 소멸자 호출
- 핵심 기반 클래스 포인터로 delete하면 기반 클래스의 소멸자만 호출된다.
    - 파생클래스 소멸자를 호출되게 하려면 viraul destructor를 사용해야 한다. - C++ 기본 문법
    - **virtual** ~myRefCountedBase(){}
- [source 3_reference3 : 195 page  ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/3_reference3.cpp)

-----------

<a name="virtual을사용하지않고파생클래스의소멸자호출"></a>

### 2.4.4\. virtual을 사용하지 않고 파생클래스의 소멸자 호출
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

<a name="참조계수를조작하는함수"></a>

### 2.4.5\. 참조 계수를 조작하는 함수
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

<a name="c++11멀티쓰레드에서안전한타입atomic"></a>

### 2.4.6\. C++11 멀티쓰레드에서 안전한 타입 (atomic)
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

<a name="thintemplate"></a>

### 2.4.7\. thin template
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

<a name="복사되면안되는classmacro:참조계수class를복사되지않게해야한다."></a>

### 2.4.8\. 복사되면 안되는 class (MACRO) : 참조 계수 class를 복사되지 않게 해야 한다. 
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

<a name="스마트포인터"></a>

### 2.4.9\. 스마트 포인터
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

<a name="thintemplate-1"></a>

## 2.5\. thin template
<a name="template는너무많은member함수를만든다."></a>

### 2.5.1\. template는 너무 많은 member 함수를 만든다.
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

<a name="void를이용하여thintemplate을더가볍게"></a>

### 2.5.2\. void를 이용하여 thin template을 더 가볍게
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

<a name="this"></a>

## 2.6\. this
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

<a name="crtp"></a>

## 2.7\. CRTP
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

<a name="예외안정성"></a>

## 2.8\. 예외 안정성
- // 예외 안정성 (exception safety)
    - 1. 완전 보장 : 예외가 없다. ex) int n=0  int *p = nullptr
    - 2. 강력 보장 : 예외가 있지만 잡아서 처리하면 객체의 상태는 예외 발생 이전 상태가 된다. 계속 사용가능하다.
    - 3. 기본 보장 : 예외가 발생해도 잡으면 자원 누수는 없다.  단, 객체의 상태는 알수 없다. 이어서 사용할수 없다.
<a name="제거와반환을분리"></a>

### 2.8.1\. 제거와 반환을 분리
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

<a name="깊은복사로구현한대입연산자:copy-and-swap"></a>

### 2.8.2\. 깊은 복사로 구현한 대입 연산자 : copy-and-swap
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



<a name="day2"></a>

# 3\. Day2

------------

<a name="new"></a>

## 3.1\. new
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

<a name="메모리할당과생성자분리"></a>

### 3.1.1\. 메모리 할당과 생성자 분리
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

<a name="00으로초기화된point를힙에10개만들자."></a>

### 3.1.2\. 0,0으로 초기화된 Point를 힙에 10개 만들자.
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

<a name="vector의메모리관리기술"></a>

###  3.1.3\. vector의 메모리 관리 기술
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

<a name="vectorresize"></a>

### 3.1.4\. vector resize
- v(10) -> v.resize(3) : 줄어든 메모리는 파괴하지 않습니다. 하지만 소멸자를 호출해야 합니다. 소멸자의 명시적 호출이 필요합니다.
- v.resize(3) -> v.resize(4) : 메모리는 이미 있으므로, 생성자의 명시적 호출이 필요합니다. (placement new를 사용해서 생성자 호출)
- [source 1_new3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/1_new3.cpp)
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------


<a name="vector를만들어보자"></a>

### 3.1.5\. vector를 만들어보자
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


<a name="###많이사용하는trycatch를std에서제공하는함수로대치"></a>

3.2\. ### 많이 사용하는 try catch를 std에서 제공하는 함수로 대치
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

<a name="traits"></a>

## 3.3\. traits
- #include <type_traits>

<a name="specialization이용한traits기능"></a>

### 3.3.1\. specialization 이용한 traits 기능
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

<a name="is_reference등.."></a>

### 3.3.2\. is_reference등..
- is_reference  ``` <T&> <T&&> ```
- is_const   ``` <const T> ```
- [source 2_traits3 115 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/2_traits3.cpp)

------------

<a name="c++11부터다양한traits를표준으로제공합니다."></a>

### 3.3.3\. c++11 부터 다양한 traits를 표준으로 제공합니다.
```cpp
#include <type_traits>
    std::cout << is_reference<int>::value << std::endl; // 0
    std::cout << is_reference<int&>::value << std::endl; // 1

    std::cout << is_const<int>::value << std::endl; // 0
    std::cout << is_const<const int>::value << std::endl; // 1
```

------------

<a name="int2type"></a>

## 3.4\. int2type

<a name="template"></a>

### 3.4.1\. template
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

<a name="int를type으로설정"></a>

### 3.4.2\. int를 type으로 설정
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

<a name="포인트따라구현부를다르게가져가는함수int2type이용+함수overloading"></a>

###  3.4.3\. 포인트  따라 구현부를 다르게 가져가는 함수 (int2type 이용 + 함수 overloading)
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

<a name="integral_constantint2type발전;c++11표준"></a>

### 3.4.4\. integral_constant (int2type 발전 ; C++11 표준)
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

<a name="포인터여부에따라다르게처리하는방법3가지-summary"></a>

### 3.4.5\. 포인터 여부에 따라 다르게 처리하는 방법 (3가지)  - Summary
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

<a name="typename"></a>

## 3.5\. typename

<a name="템플릿인자t에의존된타입을사용할때는반드시앞에typename을붙여야한다"></a>

### 3.5.1\. 템플릿 인자(T)에 의존된 타입을 사용할때는 반드시 앞에 typename을 붙여야 한다
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

<a name="평가되지않는표현식"></a>

## 3.6\. 평가되지 않는 표현식

<a name="unevaluatedexpressio:평가되지않는표현식4개"></a>

### 3.6.1\. unevaluated expressio : 평가되지 않는 표현식 4개
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

<a name="sfinae"></a>

## 3.7\. SFINAE
- Substitution Failure Is Not An Error

<a name="overloadingresolution:함수찾는순서float로시작"></a>

### 3.7.1\. overloading resolution : 함수 찾는 순서 (float로 시작)
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

<a name="함수호출시어떤함수를호출하는지는인자만가지고결정"></a>

### 3.7.2\. 함수 호출시 어떤 함수를 호출하는지는 인자만 가지고 결정
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

<a name="sfinae가적용되는위치3곳함수signature에적용"></a>

### 3.7.3\. SFINAE가 적용되는 위치 3곳 (함수 signature에 적용)
- SFINAE가 적용되는 위치 3곳 (함수 signature에 적용)
    - 1. 함수 반환값 : 가장 많이 사용되는 기술
        - ```template<typename T> typename T::type foo(T n){} ```
    - 2. 함수 인자 타입 : return type이 없는 2개중 하나인 생성자에 사용하고 싶을때
        - ```template<typename T> void foo(T n,typename T::type n2){} ```
    - 3. 템플릿 인자  : 함수의 모양이 복잡해지지 않는 특징이 있다.
        - ```template<typename T, typename T2 = typename T::type> void foo(T n) {} ```
- [source 6_SFINAE3  215 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/6_SFINAE3.cpp)


------------

<a name="enable_if"></a>

## 3.8\. enable_if

<a name="enable_if<ab>"></a>

### 3.8.1\. enable_if<A,B>
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

<a name="정수가아닌경우실패하게하고싶다.static_assert/enable_if"></a>

### 3.8.2\. 정수가 아닌 경우 실패하게 하고 싶다.static_assert / enable_if
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

<a name="type_traits:enable_if"></a>

### 3.8.3\. type_traits : enable_if
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

<a name="printv:타입에따라다른print총정리"></a>

## 3.9\. printv : 타입에 따라 다른 print  (총정리)

<a name="방법1.true_type/false_type을사용하는functionoverloading"></a>

### 3.9.1\. 방법 1. true_type / false_type을 사용하는 function overloading
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

<a name="방법2.enable_if를사용하는방법"></a>

### 3.9.2\. 방법 2. enable_if를 사용하는 방법
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

<a name="방법3.ifconstexprt-c++17style"></a>

### 3.9.3\. 방법 3. if constexprt - c++17 style
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

<a name="trivial하다."></a>

## 3.10\. trivial 하다.
- trivial : 생성자 , 복사 생성자 , 소멸자 , 대입연산자 등이 하는 일이 없을 경우 'trivial하다' 라고 한다.

<a name="trivial조건"></a>

### 3.10.1\. trivial 조건
- trivial하려면
    - 1. 가상함수가 없고
    - 2. 객체형 멤버가 없거나 멤버의 생성자가 trivial하고
    - 3. 기반 클래스가 없거나 기반클래스의 생성자가 trivial하고
    - 4. 사용자가 만든 생성자가 없을때
- [source 10_trivial1](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/10_trivial1.cpp)


------------

<a name="is_trivially_default_constructible"></a>

### 3.10.2\. is_trivially_default_constructible
- C++11 ; 그러나 , g++ version에 따라 다르므로 -std=c++17 로 compile
    - 포인터 <-> 포인터
    - 포인터 <-> 정수
    - 서로 다른 타입에 대한 참조
- [source 10_trivial2](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/10_trivial2.cpp)
```cpp
    bool b = std::is_trivially_default_constructible<Test>::value;
```

------------

<a name="복사를할때얕은/깊은복사중에서선택하기위해서trivial한지를조사한다."></a>

### 3.10.3\. 복사를 할때 얕은 / 깊은 복사중에서 선택하기 위해서  trivial한지를 조사한다.
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

<a name="atomic가능성check를위한trivial"></a>

### 3.10.4\. atomic 가능성 check를 위한 trivial
- atomic을 만들려면 복사 생성자도 만들면 안되다. 그러므로 trivial 개념이 필요하다. 
- [source 10_trivial4](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/10_trivial4.cpp)


------------

<a name="is_abstract"></a>

## 3.11\. is_abstract

<a name="std::is_abstract<>"></a>

### 3.11.1\. std::is_abstract<>
- [source 11_is_abstract1](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/11_is_abstract1.cpp)
```cpp
    std::cout << std::is_abstract<Shape>::value << std::endl;
```

------------

<a name="is_abstract의구현"></a>

### 3.11.2\. is_abstract의 구현
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

<a name="is_abstract의구현generic"></a>

### 3.11.3\. is_abstract의 구현 (Generic)
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

<a name="memberdetect"></a>

## 3.12\. member detect

<a name="예제:memberdetect"></a>

### 3.12.1\. 예제 : member detect
- **질문 : 결과 값이 1이 나와야 하는데 자꾸 0이 나옴.**  ```U() -> declval<U>()``` 으로만 바꾼 것이 4번
- [source 12_member_detect2 143 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/12_member_detect2.cpp)
- [source 12_member_detect4 143 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day2/12_member_detect4.cpp)
	- 답은 12_member_detect4.cpp 에서만 해봄.
		- template class myTest를 만들어 해보니 됨.  vector 일때만 안됨.
```cpp
template<typename T> class myTest {
        T a;
public:
        void front(){}
};

bool b = has_front_function<myTest<int>>::value; // 1
```

------------

<a name="declval"></a>

### 3.12.2\. declval()
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



<a name="day3"></a>

# 4\. Day3

------------

<a name="pointerofmemberfunction"></a>

## 4.1\. pointer of member function

<a name="pointerofmemberfunctionandinvokec++17"></a>

### 4.1.1\. pointer of member function and invoke (c++17)
- 핵심
	- 1. 일반 함수 포인터에 멤버함수 주소를 넣을수 없다.
```cpp
	void(*f1)() = &foo;	// ok 
	//void(*f2)() = &Dialog::Close; // error : 객체가 있어야 하기 때문
```
	- 2. 일반 함수 포인터에 static 멤버함수의 주소를 넣을수 있다.
```cpp
class Dialog
{
public:
	void Close() 	// voidClose(Dialog* this)
	{ 
		std::cout << "Close" << std::endl; 
	}
	static void Close2(){}
};

	void(*f3)() = &Dialog::Close2; // ok
```
	- 3. 멤버함수의 포인터를 만들고 사용하는 방법
```cpp
	// 멤버함수를 가리키는 포인터 변수 만드는 모양
	// pointer to member
	void(Dialog::*f2)() = &Dialog::Close; // ok

	// f2();  // error . 객체가 없다.
	
	Dialog dlg;
	//dlg.f2();	// error : f2라는 함수를 찾을수 없다. 
	//
	//dlg.*f2(); 	//  .*  ->* : pointer to member operator
		// error : ()이 .*보다 우선순위가 높다.
	(dlg.*f2)(); // ok
	(&(dlg)->*f2)();
```
	- 4. c++17 invoke 함수 
```cpp
	std::invoke(f1);  // f1함수 호출
	// invoke(f1,10,20);  f1(10,20)
	std::invoke(f2,&dlg);  // (dlg.*f2)()의 의미

	// invoke (f2,&dlg, 10,20);  // (dlg.*f2)(10,20)
	
	// invoke에서는 함수가 member 함수 pointer인지를 조사하여 수행하는 것이다.
```
- [source 1_member_pointer](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/1_member_pointer.cpp)
- 구조체 안에서 y의 위치 (Offset = 4) ```int Point::*p2 = &Point::y; ```
```cpp
	// 멤버 테이타를 위한 포인터
	int n= 0;
	int* p1 = &n;
	int Point::*p2 = &Point::y;	// 구조체 안에서 y의 위치 (Offset = 4)

	Point pt;
	pt.*p2 = 10;	// *( ((char*)&pt) + p2 ) = 10

	printf("%d\n",p2);	// 4 
	printf("%d\n",pt.y);	// 10 

	//p2 = p2 + 1;	// error. 멤버테이터를 가리키는 포인터는 사칙연산이 안됨
```

------------

<a name="class안의static함수의특징thread"></a>

### 4.1.2\. class안의 static 함수의 특징 (Thread)
- 핵심 1. 아래 함수는 반드시 static 멤버 함수가 되어야 합니다. 
	- static이면 첫번째 인자로 this가 오지 않습니다. 
	- static으로 하지 않으려면 class 밖으로.. 
- 안드로이드소스 /platform_system_core/libutils/include/utils/Thread.h
	- https://android.googlesource.com/platform/system/core/+/android-5.0.0_r2/include/utils/Thread.h
- [source 1_member_pointer2](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/1_member_pointer2.cpp)  Windows용
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

<a name="std::enable_shared_from_this"></a>

### 4.1.3\. std::enable_shared_from_this 
- this 포인터로 외부에서 만든 관리 객체를 공유할수 있게 하는 기반 클래스
- CRTP  ``` class Thread : public std::enable_shared_from_this<Thread> ```
- 아래 코드는 2개의 문제가 있습니다. 
	- 1. raw pointer(this)를 가지고 초기화하면 관리객체가 따로 만들어집니다.
	- 2. 생성자에서 초기화하면 관리객체를 같이 사용할때 참조계수가 즉시 2가 됩니다.
	```cpp
	Thread() : holdme(this)
	{
	}
	```
- shared_from_this() : 외부에 만들어져있는 shrad_ptr용 관리 객체를 같이 사용하게 하는 함수 
	- std::enable_shared_from_this의 member function
- [source 1_member_pointer3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/1_member_pointer3.cpp)  Windows용
```cpp
    cout << pB << endl; // 1004  because of int a => 1000 , int b => 1004
```

------------

<a name="모든함수pointer를담을수있는pointer"></a>

### 4.1.4\. 모든 함수 pointer를 담을수 있는 pointer
- 일반 함수와 멤버 함수를 함께 저장하는 class
	- void* 에는 member pointer를 못 담았다. 
 	- 일반함수 포인터 : IAction with execute()
	- 멤버함수 포인터 : IAction with execute()
- override 도 가능하면 사용해서 에러를 줄이자.
- [source 1_member_pointer7](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/1_member_pointer7.cpp)
```cpp
struct IAction
{
	virtual void Execute() = 0;
	virtual ~IAction() {}
};

//일반 함수 포일터를 관리하는 클래스
class FunctionAction : public IAction
{
	typedef void(*HANDLER)();
	HANDLER handler;
public:
	FunctionAction(HANDLER h) : handler(h) {}

	virtual void Execute() override // C++11
	{
		handler();
	}
};



template<typename T> class MemberAction : public IAction
{
	using HANDLER = void(T::*)();	// C++11. typedef와 유사
	HANDLER handler;
	T* target;
public:
	MemberAction(HANDLER h ,T* t) : handler(h), target(t){}
	virtual void Execute() override 
	{
		(target->*handler)();
	}
};

	IAction* p1 = new FunctionAction(&foo);
	IAction* p2 = new MemberAction<Dialog>(&Dialog::Close,&dlg);
```

------------

<a name="objectgenerator라는기술:makeactionmakepair"></a>

### 4.1.5\. object Generator 라는 기술 : makeAction makePair
- object Generator 라는 기술 (CRTP대신)
	- 클래스 템플릿을 직접 사용하지 말고 함수 템플릿을 통해서 만들자
		- C++11에서 함수 템플릿은 추론이 된다. 
- webkit source/wtf/wtf/scope.h 소스 참조
	- key : explicit && WTFMove
```cpp
 	makeScopeExit()
    explicit ScopeExit(ExitFunctionParameter&& exitFunction)
        : m_exitFunction(WTFMove(exitFunction))
    {
    }
```

- [source 1_member_pointer8](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/1_member_pointer8.cpp)
```cpp
template<typename T>
IAction* makeAction( void(T::*handler)() , T* target) // C++11에서 함수 템플릿은 추론이 된다. 
{
	return new MemberAction<T>(handler,target);
};

IAction* makeAction(void(*handler)())
{
	return new FunctionAction(handler);
}

int main()
{
	//IAction* p1 = new FunctionAction(&foo);
	IAction* p1 = makeAction(&foo);
	p1->Execute();	// foo 실행 
	Dialog dlg;
	//IAction* p2 = new MemberAction<Dialog>(&Dialog::Close,&dlg);	// CRTP
	IAction* p2 = makeAction(&Dialog::Close,&dlg);
	p2->Execute();	
}
```

------------

<a name="deduction"></a>

### 4.1.6\. deduction
- C++17부터는 deduction기능으로 object generator 기술은 안 쓰일 듯.
```cpp
// 함수 템플릿
square<int>(3);		// 정확한 표현
square(3);		// deduction : 템플릿 인자 생략 가능
// C++11에서 함수 템플릿은 추론이 된다. 


// 클래스 템플릿
list<int> s(10,3);
list s(10,3);		// C++17 부터는 템플릿 인자 생략 가능
			// C++14까지는 반드시 표기해야 한다.
```

------------

<a name="smartpointer"></a>

## 4.2\. smart pointer

<a name="smartpointer사용처"></a>

### 4.2.1\. smart pointer 사용처
- smart pointer는 객체 + 관리객체 (그래서 size가 거의 2배)
- 아래 코드는 절대 안됩니다.
	- 자원을 관리하기 위한 관리 객체가 sp3, sp4 각각 생성됩니다
```cpp
	int* p = new int;
	std::shared_ptr<int> sp3(p);
	std::shared_ptr<int> sp4(p);
		// sp4는 sp3의 존재를 알수 없다.
		// 이렇게 쓰면 문제가 발생하게 된다. 
		// 이렇게 절대 쓰면 안됨. 
		// 그래서 shared_ptr을 만들때 자원을 할당해야지 , 할당한 자원을 shared_ptr에 넣으면 안된다. 
```
- RAII : Resource Acquitition Is Initialization - 197 page
	- 자원을 할당하는 것은 자원 관리 객체가 초기화될때 여야 한다. 
```cpp
	std::shared_ptr<int> sp5(new int); // ok!!
```
- [source 2_smart_pointer1 : RAII 197 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/2_smart_pointer1.cpp)

------------

<a name="smartpointer객체+관리객체및make_shared"></a>

### 4.2.2\. smart pointer 객체 + 관리객체 및 make_shared
- 메모리 할당에 사용되는 operator new() 함수를 재정의 할수 있습니다.
```cpp
void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}
```
- 아래 코드는 동적 메모리 할당을 몇번 하게 될까요? 2번
```cpp
	// new Point  +   관리 객체
	std::shared_ptr<Point> sp(new Point);
```
- sizeof(Point) + sizeof(관리객체)를 한번에 메모리에 할당
```cpp
	// smart pointer를 쓰려면 make_shared를 써라
	//    memory 파편화를 막고 , size도 줄어든다
	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1,2);
```
- [source 2_smart_pointer2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/2_smart_pointer2.cpp)

```cpp
// make_shared의 원리
//  && : perfect forwardng
template<tpename T, typename ... Types>
shared_ptr<T> make_shared<T>(Types&& ... args)
{
	// 1. 메모리 할당
	void* p = operator new(sizeof(T) + sizeof(12)); // 관리객체의 크기를 12로 가정

	// 2. 메모리 윗쪽에 놓인 객체에 대해서 생성자 호출
	new(p) T(std::forward<Types>(args) ...);	// C++11완벽한 전달

	// 3. 관리 객체 초기화
	
	// 4. shared_ptr를 만들어서 반환
	char* p2 = static_cast<char*>(p);
	std::shared_ptr<T> sp;
	sp._reset( static_cast<T*>(p2) ,  // 객체 주소 
			p2 + sizeof(T)); // 관리 객체 주소 

	return sp;
}
```


---------

<a name="관리객체가가지는4가지"></a>

### 4.2.3\. 관리 객체가 가지는 4가지 
- 1. 참조계수  (strong count) : 객체 수명 관리
- 2. 삭제자
```cpp
	//std::shared_ptr<void> p2(malloc(100), 삭제자함수);
	std::shared_ptr<void> p2(malloc(100), foo);
	std::shared_ptr<void> p3(malloc(100), [](void*p) { free(p); }   );
```
- 3. 객체 pointer
- 4. weak count : 관리 걕체 수명 관리 (weak pointer때문에) 
	- weak count == 0 일때 관리 객체도 지운다.

- [source 2_smart_pointer3 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/2_smart_pointer3.cpp)



---------

<a name="weak_pointer"></a>

### 4.2.4\. weak_pointer
- 참조 계수가 증가하지 않는 스마트포인터 (raw pointer대신 이것 사용) ``` std::weak_ptr<int> wp; ```
```cpp
	std::weak_ptr<int> wp; 	// 참조 계수가 증가하지 않는 스마트포인터 (raw pointer대신 이것 사용) 

	{
		std::shared_ptr<int> sp1(new int);
		std::shared_ptr<int> sp2 = sp1;	// 참조 계수 증가

		// 수명에 관여가기 싫으면 진짜 포인터를 쓰면 된다. 
		// raw pointer(진짜 포인터)의 문제점 : 객체가 파되었는지 알수 없다.
		rp = sp1.get();	// 진짜 포인터 꺼내기
		wp = sp1;

		std::cout << sp1.use_count() << std::endl;	// 2
	}

	if(wp.expired()){
		std::cout << "wp : 객체가 파괴됨" << std::endl;
	}
```
- make_shared를 쓰면 합쳐서 관리를 한다.
	- 그러므로 , weak pointer를 사용하면 weak pointer가 없어질때까지 객체 memory도 반환되지 않는다.
	- 단지 , 소멸자만 call된다.

- android  148 line  RefBase.cpp

- [source 2_smart_pointer4 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/2_smart_pointer4.cpp)


---------

<a name="forwardingreference"></a>

## 4.3\. forwarding reference

<a name="lvaluervalue"></a>

### 4.3.1\. lvalue rvalue
- lvalue : 등호의 오니쪽에 올수 이는 표현식 (expression)
- rvalue : 등호의 왼쪽에 올수 없는 표현식
- 규칙
	- 1. & (lvalue reference) 는 lvalue만 가리킬수 있다.
	- 2. const & (const lvalue reference) 는 lvalue와 rvalue를 모두 가리킨다 
		- Point() 임시객체는 상수가 아니다.
	- 3. C++11의 && (rvalue reference)는 rvalue만 가리킬수 있다.
```cpp
		// lvalue : 등호의 오니쪽에 올수 이는 표현식 (expression)
		// rvalue : 등호의 왼쪽에 올수 없는 표현식
	// n + 1 = 10;  // n+1 : rvalue
	// (n=10) = 20;  // n = 10 : lvalue
	// foo();    이런 것은 void expression이라고 정의한다. 

	
	// n : lvalue
	// 10 : rvalue 
	//
	// 규칙 1. & (lvalue reference) 는 lvalue만 가리킬수 있다.
	int& r1 = n; // ok
	int& r2 = 10;	// error

	// 규칙 2. const & (const lvalue reference) 는 lvalue와 rvalue를 모두 가리킨다 
	const int& r3 = n;	// ok
	const int& r4 = 10;	// ok : 가리킬수는 있지만 상수성 추가
		// Point() 임시객체는 상수가 아니다.

	// 규칙 3. C++11의 && (rvalue reference)는 rvalue만 가리킬수 있다.
	int&& r5 = n;	// error
	int&& r6 = 10;  // ok
```

- [source 3_forwarding_reference1 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference1.cpp)

---------

<a name="인자type에다른함수우선순위"></a>

### 4.3.2\. 인자 type에 다른 함수 우선 순위
-  우선순위
	- int& ```void foo(int& a){ std::cout << __PRETTY_FUNCTION__ << std::endl; }```
	- const int& ```void foo(const int& a){ std::cout << __PRETTY_FUNCTION__ << std::endl; }```
	- int&&```void foo(int&& a){ std::cout << __PRETTY_FUNCTION__ << std::endl; }```
- 변수로 존재하면 무조건 lvalue
```cpp
	int&& r2 = 10;
	foo(r2);	// 1번  : r2는 lvalue이므로 1번
```

- [source 3_forwarding_reference2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference2.cpp)


---------

<a name="referencecollapsing:레퍼런스붕괴"></a>

###  4.3.3\. reference collapsing : 레퍼런스 붕괴
- & & 이중 reference with typedef or using
	- typedef / using / template 같은 것으로 정의 할때는 & & 사용가능하다. 
- 단지 && && 만 &&
```cpp
	using LREF = int&;
	using RREF = int&&;

	// typedef같은 것으로 정의 할때는 & & 사용가능하다. 
	// reference collapsing : 레퍼런스 붕괴
	LREF& ll = n ;		// & & => &    lvalue이므로 n
	LREF&& lr = n ;		// & && => &
	RREF& rl = n ;		// && & => &
	RREF&& rr = 10 ;		// && && => &&
```
- [source 3_forwarding_reference3 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference3.cpp)


---------

<a name="typenamet를고려한lvaluervalue"></a>

### 4.3.4\. typename T를 고려한 lvalue rvalue
- 함수 인자로 
	- int&  : int의 lvalue만 전달 가능
	- int&& : int의 rvalue만 전달 가능
	- T&    : 모든 타입의 lvalue만 전달 가능
	- T&&   : 모든 타입의 lvalue와 rvalue 전달 가능
-  **위/아래의 모든 경우를 종합하면 **
	- lvalue(n)을 보내면 T:int&    함수(int&)     	f(T)
	- rvalue(0)을 보내면 T:int     함수(int&&)	f(T&&)
```cpp
template<typename T> void f3(T& a){}
// f3<int>( n );
// f3<int&>( n );
// f3<int&&>( n );

template<typename T> void f4(T&& a){}
// f4<int>( 10 );
// f4<int&>( n );
// f4<int&&>( 10 );

	f1(n);	// T : int&  f1(int&)
	f1(10);	// T : int   f1(int&&)
```

- 사용자 타입을 직접 전달하면 어떤 함수가 생성될지 생각해 봅시다.
```cpp
	 f4<int>( 10 );		// T:int   T&&:int&&      f4(int&& ) 
	 f4<int&>( n );		// T:int&  T&&:int& &&    f4(int&)
	 f4<int&&>( 10 );	// T:int&& T&&:int&& &&   f4(int&&)
```
	
- 타입을 지정하지 않을때 (함수 템플릿)
```cpp
	 f4(n);		// T: int&으로 결정   f4(int&)
	 f4(0);		// compiler는 T를 간략한 것을 선택
	 		// T:int 으로 결정  f4(int&&)
```

- [source 3_forwarding_reference4 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference4.cpp)


---------

<a name="lvalue와rvalue를모두전달받는함수만들기"></a>

### 4.3.5\. lvalue와 rvalue를 모두 전달받는 함수 만들기
-  lvalue와 rvalue를 모두 전달받는 함수 만들기
	- 1. call by value : 복사본
		- ```void f1(int a){}```
	- 2. const lvalue reference (그러나, const로 못 바꾼다.)
		- ```void f1(const int& a){}```
	- 3.  2개의 함수 : 변경가능하도록 원본 그대로를 받고 싶다.
		- ```void f1(int&  a){}```
		- ```void f1(int&& a){}```
	- 4. 2개의 함수를 자동생성
		- T&& : forwarding reference(universal reference 라고도 한다.)
		- int&& : rvalue reference
		- ```template<typename T> void f1(T&& a) {} ```
- [source 3_forwarding_reference5 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference5.cpp)


---------

<a name="2개의함수를이용한함수전부받아주기방식구현"></a>

###  4.3.6\. 2개의 함수를 이용한 함수 전부 받아주기 방식 구현
```cpp
void foo(int&  arg){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
void foo(int&& arg){ std::cout << __PRETTY_FUNCTION__ << std::endl; }

//void forwarding(const int& n){ foo(n); }
//const도 안된다. 해결책은 함수 2개
void forwarding(int& n){ foo(n); }
void forwarding(int&& n){ 
	// main에서 10(rvalue)를 보냈는데
	// int&& n = 10으로 받으면서 lvalue가 되었다.
	// 즉 , value의 특성이 변경되었다.
	// 원래 rvalue로 캐스팅해서 전달해야 foo(int&&)이 수행된다. 
	foo( static_cast<int&&>(n) ); 
}
```

- [source 3_forwarding_reference6 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference6.cpp)


---------

<a name="template으로변환을하자"></a>

### 4.3.7\. template으로 변환을 하자
- 1. 함수 인자를 T&& 로 받아서
- 2. 다른 곳에 보낼때는 std::forward<T>(arg)로 묶어서 전달
```cpp
// void forwarding(int& n){ foo( static_cast<int&>(n) ); }
// void forwarding(int&& n){ foo( static_cast<int&&>(n) ); }

template<typename T>
void forwarding(T&& n)
{ 
	//foo( static_cast<T&&>(n) );  
	foo( std::forward<T>(n) ); 	// forward안에서 위처럼 캐스팅
}
// Charles : T T 일때는 모두 int&&으로 나온다.
// 10 => T : int   T&& : int&&
// n  => T : int&  T&& : int&
```
- [source 3_forwarding_reference7 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference7.cpp)


---------

<a name="example:make_shared"></a>

### 4.3.8\. example: make_shared
```cpp
template<typename T,typename ARG>
void make_shared(ARG&& arg)
{
	void *p = operator new(sizeof(T) );
	new(p) T(std::forward<ARG>(arg));
}
```
- [source 3_forwarding_reference8 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference8.cpp)


---------

<a name="forwardingreference-1"></a>

### 4.3.9\. forwarding reference
- forwarding reference일까요?
	- class 가  template인 것은 의미가 없다.
	- 함수가 template이면서 T&& 으로 될때 forwarding reference 입니다.
```cpp
template<typename T> class Test
{
public:
	// 아래 코드는 forwarding reference일까요?
	// 아닙니다.
	// 클래스가 템플릿이지 함수 자체가 템플릿이 아닙니다.
	// 클래스 생성시 이미 T 타입이 결정됩니다. 
	// 그래서 , forwarding reference가 아닙니다. 
	void foo(T&& arg){}

	// 아래 코드가 forwarding reference 입니다.
	template<typename U> void goo(U&& arg) {}
};
```
- [source 3_forwarding_reference9 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference9.cpp)


---------
<a name="생성자모양"></a>

### 4.3.10\. 생성자 모양
- 생성자 모양 1. call by value
	- ```pair(T a , U b) : first(a) , second(b) {}```

- 생성자 모양 2. non const lvalue reference
	- ```pair(T& a , U& b) : first(a) , second(b) {}```

- 생성자 모양 3. const lvalue reference
	- ```pair(const T& a , const U& b) : first(a) , second(b) {}```
		- ** 모든 참조는 const 입니다. **
		- pair<int& 을 주면
		- 뒤에 const U&을 할때 int&이 자동으로 const를 포함하므로
		- const U&의 const가 사라집니다.  
		- 왜냐면 &자체가 const를 쓰지 않아도 의미를 가지고 있기 때문입니다.
		- [source reference2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/reference2.cpp)
```cpp
	int& r = n;   // r이 한번 set되면 가리키는 곳은 절대 바뀌면 안된다. 
			// 그러므로 int& const r = n; 이 되는 것이다.
			// 그래서 위에서 모든 참조는 const라고 하는 것이다. 

	template<typename T> void goo(T const a)
	goo<int&>(&n);	// goo( int& const&)
			// 모든 참조는 const 입니다. 따라서  const는 빠집니다. 
			// goo(int& &) 가
			// goo(int &)가 됩니다. 
```

- 생성자 모양 4 : C++11 이후 스타일
	- ```template<typename A , typename B> pair(A&& a,B&& b) : first(std::forward<A>(a)) , second(std::forward<B>(b)){} ```

- call by value 일때 type deduction 할때는 const가 사라진다. 
- example : pair (2개의 값을 보관하는 구조)
- [source 3_forwarding_reference10 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference10.cpp)


---------

<a name="forwardingreference기본template"></a>

### 4.3.11\. forwarding reference 기본 template 
-  forwarding reference로만 받아야 하는 이유
	- lamda 식은 rvalue
	- mutable을 붙인 lamda식은 비상수 멤버 함수로 const로 못 받음. 
```cpp
template<typename T> void foo(T&& f)
{
	std::forward<T>(f)();
}
```

- lamda 사용 예
```cpp
	// 람다표현식은 rvalue 입니다. 
	foo([](){ std::cout << "lamba" << std::endl; } ); 	// ok
	// mutable 람다표현식 : () 연산자 함수를 비상수 멤버 함수로 해달라는 의미
	// 그러므로 const로 받을수는 없다. 
	foo([]() mutable { std::cout << "mutable lamba" << std::endl; } ); 
```

- [source 3_forwarding_reference11 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference11.cpp)


---------

<a name="lvaluervalue를위한member함수선언"></a>

### 4.3.12\. lvalue rvalue를 위한 member 함수 선언
```cpp
struct Test
{
	// lvalue 객체에서만 부를수 있다. 
	void foo() & {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	// rvalue 객체에서만 부를수 있다. 
	void foo() && {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

	Test().foo();	// foo() &&
```
- [source 3_forwarding_reference12 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/3_forwarding_reference12.cpp)


---------

<a name="const"></a>

## 4.4\. const 

<a name="const의위치에따른의미"></a>

### 4.4.1\. const 의 위치에 따른 의미
-  pointer가 아닐때는 위치에 상관없이 같은 의미
```cpp
	const int c1 = 10;
	int const c2 = 10;  // 이 2개는 같다. pointer가 아닐때는 같다.
	// pointer를 사용할때만 * 앞뒤 에 const를 붙이는 의미가 달라진다.
```

-  pointer 와 같이 사용시는 위치에 따라 다른 의미를 가진다. 
```cpp
	virtual void foo(const int* a) override    // compile시 error가 있었을 것임.
	virtual void foo(int* const a)		// 보통 a가 변하지 않게 하기 위한 것으로 이것을 사용해야 한다. 

template<typename T> class Base
{
public:
	// a는 const 입니다. 
	virtual void foo(T const a)	// <== 이렇게 사용하는 것을 기본으로 
	{
		std::cout << "Baee foo" << std::endl;
	}
};
```
- [source reference ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/reference.cpp)


---------

<a name="temporary:임시객체"></a>

## 4.5\. temporary : 임시객체

<a name="객체의종류"></a>

### 4.5.1\. 객체의 종류
- 이름 있는 객체 Point p1(1,2);
- 임시객체 : unnamed object 
```cpp
	Point(1,2);  // 임시객체. unnamed object
		// 자기를 만든 문장의 끝에서 파괴
	Point(1,2) , std::cout << "X" << std::endl;
	Point&& r = Point(1,2);

```

- [source 4_temporary1 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/4_temporary1.cpp)


---------

<a name="임시객체의특징"></a>

### 4.5.2\. 임시객체의 특징
- 임시객체는 왼쪽에 올수 없다. (rvalue)
- rvalue는 주소를 구할수 없다. (&rvalue : error)
```cpp
	Point pt(0,0);
	pt.x = 10; // ok

	Point(0,0).x = 10; //  임시객체는 왼쪽에 올수 없다. 
			  // 임시객체는 rvalue이다. 

	Point* p1 = &pt; 		// ok 
	Point* p2 = &Point(0,0);	// error. rvalue는 주소를 구할수 없다. 

	Point& p1 = pt;			// ok 
	Point& p2 = Point(0,0);		// error . 이렇게 해도 수명 연장이 되지 않는다. 
			// &는 lvalue <- rvalue 은 안된다.

	// const lvalue reference는 lvalue와 rvalue를 모두 가리킨다.
	const Point& r3 = Point(0,0);		// 수명도 연장된다. 
	r3.x = 10 // error  : 상수성이 추가됨.

	Point&& r4 = Point(0,0);
	r4.x = 10; // ok
```
- [source 4_temporary2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/4_temporary2.cpp)


---------

<a name="임시객체사용예"></a>

### 4.5.3\. 임시객체 사용예
```cpp
	// 함수 인자로 임시 객체를 전달하는 경우가 많다. **
	foo(Point(1,2));

	goo(std::is_pointer<T>());	// 이렇게 임시객체 사용
```
- [source 4_temporary3 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/4_temporary3.cpp)


---------

<a name="returnbyvalue"></a>

### 4.5.4\. return by value
- call by value : 복사본이 생성
- return by value : 복사본 생성
	- 리턴용 임시객체 생성 ``` Point goo() { return pt; } ```
- return by reference
	- 임시객체를 만들지 말라는 의도 ```Point& hoo() { return pt; }``` 
```cpp
Point pt(0,0);
// call by value : 복사본이 생성
void foo(Point p){}
// return by value : 복사본 생성
// 리턴용 임시객체 생성
Point goo() { return pt; }
Point& hoo() { return pt; }	// 임시객체를 만들지 말라는 의도
	goo().x = 10;  // error : return value이므로 임시객체
	hoo().x = 10; // ok..
```
- [source 4_temporary4 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/4_temporary4.cpp)


---------

<a name="참조캐스팅"></a>

### 4.5.5\. 참조 캐스팅
- 값 캐스팅 : 임시객체 생성
- 참조 캐스팅 : 임시객체 생성 안 함.
```cpp
	static_cast<Base>(d).value = 100;	// error
	static_cast<Base&>(d).value = 100;	// ok
```
- [source 4_temporary5 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/4_temporary5.cpp)


---------

<a name="복사생성자모양"></a>

### 4.5.6\. 복사 생성자 모양 
- 1 . call by value
	- 복사 생성자를 무한히 호출하는 표현 - error
	- ```Point(Point p){} // Point p = p1``` 인자를 부르는데 , 또 부른다.  무한루프므로 error
- 2. 참조 사용
	- rvalue를 받을수 없다. 즉 , 값을 반환하는 함수의 반환값을 받을수 없다.
	- ```Point(Point& p){}	// Point& p = p1```
- 3. const lvalue reference
	- lvalue 와 rvalue를 모두 받을수 있다. 
```cpp
	Point(const Point& p) {
		std::cout << "lvalue 일대 복사 생성자"  << std::endl;
	}
	Point(Point&& p) {
		std::cout << "rvalue일때. Move 생성자"  << std::endl;
	}
```

- [source 4_temporary6 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/4_temporary6.cpp)

---------


