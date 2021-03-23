#include <iostream>
#include <type_traits>

// github 에서 4_trivial3.cpp 받아두세요 - 어제 수업소스중 한개 입니다.

// 14:00 부터 시작 합니다.



// static_assert                        : 조건을 만족하지 않으면 무조건 에러
// enable_if 를 사용한 반환 타입 만들기 : 조건을 만족하지 않으면 "함수생성안함"
//								동일 이름의 다른 함수가 있다면 사용가능.

template<typename T>
//typename std::enable_if< std::is_integral_v<T>, T>::type 
std::enable_if_t< std::is_integral_v<T>, T>
gcd(T a, T b)
{
	//static_assert(std::is_integral_v<T>, "error, T is no integer");

	return 0;
}

double gcd(double, double) { std::cout << "double" << std::endl; return 0; }

int main()
{
	gcd(6, 9);

	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f); 
}
