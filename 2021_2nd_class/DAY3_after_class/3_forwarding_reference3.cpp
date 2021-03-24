#include "cppmaster.h"

template<typename T> void foo(T&& arg)
{
	// __FUNCTION__ : 함수의 이름을 담고 있는 매크로, C++ 표준
	// std::cout << __FUNCTION__ << std::endl;

	// __FUNCSIG__         : 함수 signature를 포함한 이름 VC++ 전용
	// __PRETTY_FUNCTION__ : 함수 signature를 포함한 이름 g++ 전용

//	std::cout << __FUNCSIG__ << std::endl;
//	std::cout << __PRETTY_FUNCTION__ << std::endl;

	LOG_FUNCTION_NAME(); // cppmaster.h 에 있는 매크로 함수
}

int main()
{
	int n = 10;

	foo(n);  // T=int&    T&&=int& && => int& 
	foo(10); // T=int     T&&=int&&

	const int c = 10;
	foo(c); 
}

// T&&       : forwarding reference => lvalue 와 rvalue를 모두 받을수 있다.
// const T&& : forwarding reference 아닙니다.
//			   const rvalue reference 로 취급됩니다. 
//					( move 와 완벽한전달에 사용할수 없기 때문에 이렇게 결정)

// const T&& 로 받으면 rvalue 만 받을수 있습니다.







