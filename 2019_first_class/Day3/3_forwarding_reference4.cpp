/* 3_forwarding_reference4
- 
*/

#include <iostream>
//using namespace std;

/*
- 함수 인자로 
	- int&  : int의 lvalue만 전달 가능
	- int&& : int의 rvalue만 전달 가능
	- T&    : 모든 타입의 lvalue만 전달 가능
	- T&&   : 모든 타입의 lvalue와 rvalue 전달 가능
*/

// 위/아래의 모든 경우를 종합하면
// lvalue(n)을 보내면 T:int&    함수(int&)   f(T)
// rvalue(0)을 보내면 T:int     함수(int&&)  f(T&&)


void f1(int& a){}
void f2(int&& a){}

template<typename T> void f3(T& a){}
// f3<int>( n );
// f3<int&>( n );
// f3<int&&>( n );

template<typename T> void f4(T&& a){}
// f4<int>( 10 );
// f4<int&>( n );
// f4<int&&>( 10 );

int main()
{
	int n = 0;

	// 사용자 타입을 직접 전달하면 어떤 함수가 생성될지 생각해 봅시다.
	 f4<int>( 10 );		// T:int   T&&:int&&      f4(int&& ) 
	 f4<int&>( n );		// T:int&  T&&:int& &&    f4(int&)
	 f4<int&&>( 10 );	// T:int&& T&&:int&& &&   f4(int&&)
	
	 // 타입을 지정하지 않을때 (함수 템플릿)
	 f4(n);		// T: int&으로 결정   f4(int&)
	 f4(0);		// compiler는 T를 간략한 것을 선택
	 		// T:int 으로 결정  f4(int&&)

}
