#include <iostream>
#include <type_traits>

// 방법 1. C++17 constexpr
template<typename T> void printv(const T& v)
{
	if constexpr ( std::is_pointer_v<T> )
		std::cout << v << " : " << *v << std::endl;
	else 
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

