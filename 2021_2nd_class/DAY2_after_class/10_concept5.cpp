// 10_concept5
#include <iostream>
#include <type_traits>

/*
template<typename T> requires (sizeof(T) > 1)
void foo(T a)
{
	std::cout << "1" << std::endl;
}

template<typename T> requires (sizeof(T) > 1 && sizeof(T) < 8)
void foo(T a)
{
	std::cout << "2" << std::endl;
}
*/
template<typename T> 
concept MoreThan1 = sizeof(T) > 1;

template<typename T>
concept LessThan8 = sizeof(T) < 8;

template<typename T>
concept MoreThan1AndLessThan8 = MoreThan1<T> && LessThan8<T>;
//-------------------------------------------------
template<typename T> requires MoreThan1<T>
void foo(T a)
{
	std::cout << "1" << std::endl;
}

template<typename T> requires MoreThan1AndLessThan8<T>
	void foo(T a)
{
	std::cout << "2" << std::endl;
}

int main()
{
	foo(3);
}