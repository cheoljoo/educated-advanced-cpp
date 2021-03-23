#include <iostream>


// int a    => 변수이름 : a   a의 타입 : int
// int x[3] => 변수이름 : x   x의 타입 : int[3]
//										 T[N] : 크기를 알수 있는 배열
//										 T[]  : array of unknown bound
//												(C 언어 flexible array 에서 사용)

template<typename T> struct is_array
{
	static constexpr bool value = false;
	static constexpr int size = -1;
};
template<typename T> struct is_array<T[]>
{
	static constexpr bool value = true;
	static constexpr int size = -1;
};
template<typename T, int N> struct is_array<T[N]>
{
	static constexpr bool value = true;
	static constexpr int size = N;
};

template<typename T> void foo(const T& a)
{
	// T : int[3]
	if (is_array<T>::value) 
		std::cout << "배열, 크기는 " << is_array<T>::size  << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int x[] = { 1,2,3 }; // 이 코드는 "int x[3] = { 1,2,3 };" 입니다.

	foo(x);
}
// is_pointer 변경해서 is_array 만들어 보세요