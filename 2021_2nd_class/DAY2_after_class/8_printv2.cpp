#include <iostream>
#include <type_traits>

// 방법 2. true_type/false_type을 사용한 오버로딩

template<typename T> void printv_imp(const T& v, std::true_type)
{
	std::cout << v << " : " << *v << std::endl;
}
template<typename T> void printv_imp(const T& v, std::false_type)
{
	std::cout << v << std::endl;
}
template<typename T> void printv(const T& v)
{
	printv_imp(v, std::is_pointer<T>()); // is_pointer 의 객체 생성
}
int main()
{
	int n = 10;
	printv(n);
}