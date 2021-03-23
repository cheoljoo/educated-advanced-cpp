/* 3_forwarding_reference11
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

//template<typename T> void foo(const T& f)
template<typename T> void foo(T&& f)
{
	//f();
	std::forward<T>(f)();
}

void goo() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

int main()
{
	foo(&goo);

	// 람다표현식은 rvalue 입니다. 
	foo([](){ std::cout << "lamba" << std::endl; } ); 	// ok
	// mutable 람다표현식 : () 연산자 함수를 비상수 멤버 함수로 해달라는 의미
	// 그러므로 const로 받을수는 없다. 
	foo([]() mutable { std::cout << "mutable lamba" << std::endl; } ); 
}
