#include <iostream>
#include <type_traits>

// 방법 4. C++20 Concept 문법 - C++20의 1번째로 이야기되는 신기술
//sort()
// vc는 빌드 안됩니다.  
// g++ 8_printv4.cpp -std=c++20
template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	std::cout << v << std::endl;
}
int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

