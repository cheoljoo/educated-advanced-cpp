#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// 1. 구조체 템플릿을 만들고 "using type = T" 를 넣어라
template<typename T> struct remove_pointer
{
	// typedef T type; // C++11 이전의 스타일
	using type = T;	   // C++11 이후 코딩 스타일
};

// 2. 원하는 타입을 얻을수 있도록, 부분특수화를 통해서 타입을 분할(int* => int와 *로 분할)
template<typename T> struct remove_pointer<T*>
{
	using type = T;	
};

int main()
{
	remove_pointer<int*>::type n; // int n

	std::cout << typeid(n).name() << std::endl;
}
