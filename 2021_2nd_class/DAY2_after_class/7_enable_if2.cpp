#include <iostream>
#include <type_traits>
// static_assert :  조건을 만족하지 않으면 무조건 컴파일 에러!!

// 조건을 만족하지 않을때 "에러를 나게 하지 말고", 
// 후보군에서 빠지면 "동일 이름의 다른 버전 함수"를 호출할수 있다.

template<typename T> T gcd(T a, T b)
{
	static_assert( std::is_integral_v<T>, "error, T is no integer");

	return 0;
}

double gcd(double, double) { std::cout << "double" << std::endl; return 0; }

int main()
{
	gcd(6, 9);

	gcd(3.1,  5.4); // exactly matching
	gcd(3.1f, 5.4f); // float 버전!!!
}
