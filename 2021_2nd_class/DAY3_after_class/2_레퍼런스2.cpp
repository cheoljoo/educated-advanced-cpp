#include <iostream>

// 아래 처럼 오버로딩 가능합니다.
void foo(int& a)       { std::cout << "int&" << std::endl; }
void foo(const int& a) { std::cout << "const int&" << std::endl; }
void foo(int&& a)      { std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// 1번 호출, 없으면 2번 호출
	foo(10);	// 3번 호출, 없으면 2번 호출

	int& r1 = n;
	foo(r1); // 1번 호출, 없으면 2번 호출

	int&& r2 = 10;	// 10은 이름이 없지만, r2는 이름이 있습니다.
					// 10은 rvalue 이지만, r2는 lvalue 입니다.

	//				타입			value 속성
	// 10			int             rvalue
	// r2			int&&           lvalue

	foo(r2); // 1번 호출, 없으면 2번

	foo(static_cast<int&&>(r2)); // r2라는 lvalue 를 
								// rvalue로 캐스팅하는 코드
								// 타입 캐스팅이 아니라 value 를 변경하는 캐스팅입니다.
					
}							
void goo(int&&) {} // 인자로 int&& 타입을 받겠다는 것이 아니라!!!
				   // 인자로 rvalue를 받겠다는 것!!!!






