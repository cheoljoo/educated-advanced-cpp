#include <iostream>

template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};
using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {}; 

// integral_constant 4번에서 printv_imp() 부터 아래로 모두 복사

template<typename T> void printv_imp(const T& v, true_type )
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void printv_imp(const T& v, false_type )
{
	std::cout << v << std::endl;
}

template<typename T> void printv(const T& v)
{
	printv_imp(v, is_pointer<T>() ); // is_pointer 의 객체 생성
}



int main()
{
	int n = 10;
	printv(n);
}



