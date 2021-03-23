/* 3_forwarding_reference5
- 
*/

#include <iostream>
//using namespace std;

/*
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
*/

template<typename T> void f1(T&& a)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
	int n = 0;
	f1(n);	// T : int&  f1(int&)
	f1(10);	// T : int   f1(int&&)
}
