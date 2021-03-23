#include <iostream>
#include <type_traits>
// C++표준에는 remove_pointer 만 있습니다. 
// remove_all_pointer 는 표준에는 없습니다
template<typename T> struct remove_all_pointer
{
	using type = T;	 
};

template<typename T> struct remove_all_pointer<T*>
{
	using type = typename remove_all_pointer<T>::type; // 재귀!
};

int main()
{
	remove_all_pointer<int***>::type n; // int n

	std::cout << typeid(n).name() << std::endl;
}
