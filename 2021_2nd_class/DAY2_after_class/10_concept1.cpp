// 10_concept1
#include <iostream>
#include <type_traits>
#include <concepts>

// template : 모든 타입 함수 생성
// concept 문법 : template 사용시 조건을 만족할때만 사용하겠다.

// 타입이 가져야 하는 조건을 명시하는 문법
template<typename T>
concept Addable = requires(T a, T b)
{
	{a + b};
	{a - b};
//	typename T::type;
//	a.foo();
};

//template<typename T> requires std::is_integral_v<T>
template<typename T> requires Addable<T>
void foo(T a)
{
}

int main()
{
	int n = 10;
	foo(n);
}