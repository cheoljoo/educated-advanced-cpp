

# Day3

------------

## pointer of member function

### pointer of member function and invoke (c++17)
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

### class안의 static 함수의 특징 (Thread)
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

### std::enable_shared_from_this 
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

### 모든 함수 pointer를 담을수 있는 pointer
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

### object Generator 라는 기술 : makeAction makePair
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

### deduction
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

## smart pointer

### smart pointer 사용처
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

### smart pointer 객체 + 관리객체 및 make_shared
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

### 관리 객체가 가지는 4가지 
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

### weak_pointer
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

## forwarding reference

### lvalue rvalue
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

### 인자 type에 다른 함수 우선 순위
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

###  reference collapsing : 레퍼런스 붕괴
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

### typename T를 고려한 lvalue rvalue
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

### lvalue와 rvalue를 모두 전달받는 함수 만들기
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

###  2개의 함수를 이용한 함수 전부 받아주기 방식 구현
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

### template으로 변환을 하자
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

### example: make_shared
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

### forwarding reference
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
### 생성자 모양
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

### forwarding reference 기본 template 
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

### lvalue rvalue를 위한 member 함수 선언
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

## const 

### const 의 위치에 따른 의미
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

## temporary : 임시객체

### 객체의 종류
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

### 임시객체의 특징
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

### 임시객체 사용예
```cpp
	// 함수 인자로 임시 객체를 전달하는 경우가 많다. **
	foo(Point(1,2));

	goo(std::is_pointer<T>());	// 이렇게 임시객체 사용
```
- [source 4_temporary3 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/4_temporary3.cpp)


---------

### return by value
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

### 참조 캐스팅
- 값 캐스팅 : 임시객체 생성
- 참조 캐스팅 : 임시객체 생성 안 함.
```cpp
	static_cast<Base>(d).value = 100;	// error
	static_cast<Base&>(d).value = 100;	// ok
```
- [source 4_temporary5 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day3/4_temporary5.cpp)


---------

### 복사 생성자 모양 
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


