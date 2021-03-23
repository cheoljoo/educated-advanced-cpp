#include <iostream>

/*
template<typename T>
void foo(T a)  // void foo(int a)
{
	typename T::type n; // 에러 일까요 ? SFINAE 가 적용될까요 ? 에러
	// int::type n
	std::cout << "T" << std::endl; 
}
*/
// SFINAE 는 함수 블럭안의 문장에서는 적용되지 않습니다.
// 1. 함수의 리턴 타입
// 2. 함수의 인자 타입
// 3. 함수의 템플릿 인자 
// 에서만 적용됩니다.

// 1. 리턴 타입에 적용
// template<typename T>
// typename T::type foo(T a) { return 0; }

// 2. 함수 인자 타입
//template<typename T>
//int foo(T a, typename T::type n = 0) { return 0; }

// 3. 템플릿 인자에 적용
template<typename T,
		 typename T2 = typename T::type> 
int foo(T a) { return 0; }


void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	foo(3);
}
