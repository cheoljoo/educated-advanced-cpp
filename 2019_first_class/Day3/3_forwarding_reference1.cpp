/* 3_forwarding_reference1
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

int main()
{
	int n= 0;
	n = 10;		
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
}
