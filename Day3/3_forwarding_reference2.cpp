/* 3_forwarding_reference2
- 
*/

#include <iostream>
//using namespace std;

/*
-  우선순위
	- void foo(int& a){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
	- void foo(int&& a){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
	- void foo(const int& a){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
*/

// __FUNCTION__ : C++ 표준 매크로 , 함수 이름을 나타낸다.
// __PRETTY_FUNCTION__  :  함수 이름 + signature , g++ 전용
// __FUNCSIG__ : VC 전용
void foo(int& a){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
void foo(const int& a){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
void foo(int&& a){ std::cout << __PRETTY_FUNCTION__ << std::endl; }

int main()
{
	int n= 0;
	foo(n); 	// 1번 호출 , 없으면 2번

	foo(10);	// 3 번 호출 , 없으면 2번 (cons는 나중에)

	int& r = n;
	foo (r);	// 1번 호출 , 없으면 2번

		// 10은 메모리가 없고 값만 있다.
		// r2는 이름이 있고 왼쪽에 올수 있다. 따라서 lvalue
	int&& r2 = 10;
	// 10 = 20; // error . 10이 rvalue . 
	// r2 = 20; // ok
	foo(r2);	// 1번  : r2는 lvalue이므로 1번
	foo(static_cast<int&&>(r2)); // 3번
}
