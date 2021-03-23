// 10_concept1
#include <iostream>
#include <type_traits>
#include <concepts>

// template : ��� Ÿ�� �Լ� ����
// concept ���� : template ���� ������ �����Ҷ��� ����ϰڴ�.

// Ÿ���� ������ �ϴ� ������ ����ϴ� ����
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