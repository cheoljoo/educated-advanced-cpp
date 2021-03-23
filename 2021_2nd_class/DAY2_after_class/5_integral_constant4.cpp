// 2번 복사해 오세요... 
// 3번에서 int2type 만 복사해오세요

// integral_constant1.cpp
#include <iostream>
#include <type_traits>

// 2000년 경에 만들어지 기술
// C++11 만들때 "발전 시켜서" 표준에 추가
template<int N> struct int2type
{
	enum { value = N };
};

template<typename T> void printv_imp(const T& v, int2type<1> )
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void printv_imp(const T& v, int2type<0> )
{
	std::cout << v << std::endl;
}

template<typename T> void printv(const T& v)
{
	printv_imp(v, int2type < std::is_pointer_v<T> >()  );
				// int2type<0>() => int2type<0> 의 임시객체 생성
				// int2type<1>()
}



int main()
{
	int n = 10;
	printv(n);
}

