#include <iostream>
#include <type_traits>

// ��� 4. C++20 Concept ���� - C++20�� 1��°�� �̾߱�Ǵ� �ű��
//sort()
// vc�� ���� �ȵ˴ϴ�.  
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

