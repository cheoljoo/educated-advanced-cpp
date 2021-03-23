#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

int main()
{
	remove_pointer<int*>::type n;

	std::cout << typeid(n).name() << std::endl;
}
