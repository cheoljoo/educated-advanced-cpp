#include <iostream>
#include <type_traits>

// ¹æ¹ý 3. C++11 enable_if

template<typename T> 
std::enable_if_t< std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> 
std::enable_if_t< !std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << v << std::endl;
}
int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

