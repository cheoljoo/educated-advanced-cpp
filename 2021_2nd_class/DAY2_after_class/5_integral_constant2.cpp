// integral_constant1.cpp
// traits7번 복사해오세요. - 주석 제거
#include <iostream>
#include <type_traits>


template<typename T> void printv_imp(const T& v, YES )
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void printv_imp(const T& v, NO)
{
	std::cout << v << std::endl;
}

template<typename T> void printv(const T& v)
{
	// 함수 오버로딩으로 사용한 조건 분기
	printv_imp(v, std::is_pointer_v<T> ); 
					// true  => 1
					// false => 0
					// 1, 0은 같은 타입(int). 같은 타입으로 오버로딩 할수없다.
}



int main()
{
	int n = 10;
	printv(n);
}

