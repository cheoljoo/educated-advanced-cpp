/* 3_forwarding_reference7
- template으로 변환하자.
*/

#include <iostream>
//using namespace std;

/*
- 
*/

void foo(int&  arg){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
void foo(int&& arg){ std::cout << __PRETTY_FUNCTION__ << std::endl; }

// void forwarding(int& n){ foo( static_cast<int&>(n) ); }
// void forwarding(int&& n){ foo( static_cast<int&&>(n) ); }

// 1. 함수 인자를 T&& 로 받아서
// 2. 다른 곳에 보낼때는 std::forward<T>(arg)로 묶어서 전달
template<typename T>
void forwarding(T&& n)
{ 
	//foo( static_cast<T&&>(n) );  
	foo( std::forward<T>(n) ); 	// forward안에서 위처럼 캐스팅
}
// Charles : T T 일때는 모두 int&&으로 나온다.
// 10 => T : int   T&& : int&&
// n  => T : int&  T&& : int&

int main()
{
	int x = 10;
	forwarding(x);
	forwarding(10);
}
