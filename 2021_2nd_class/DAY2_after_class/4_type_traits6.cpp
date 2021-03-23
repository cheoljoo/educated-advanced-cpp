#include <iostream>

// type traits 
// 1999년 경에서 발견된 기술
// 2000년대 초반에 아주 많은 traits 가 개발됨.
// 2011년 C++ 표준에 채택

// C++ 표준 traits 사용법 정리
// 1. 헤더 추가
#include <type_traits>  // C++11에서 추가된 헤더

// C++11 의 using template 문법
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;

template<typename T> void foo(T a)
{
	// 1. 타입의 조사
	bool b1 = std::is_pointer<T>::value;
	bool b2 = std::is_pointer_v<T>;  // C++17 부터 지원되는 표기법

	// 2. 변형 타입 얻기
	typename std::remove_pointer<T>::type n1;  // 주의 템플릿 의존적인 경우 typename 필요
//	remove_pointer_t<T> n2; // 위와 동일한 표기법.
	std::remove_pointer_t<T> n3; // C++14부터 표준으로 채택, 원리는 위 소스 참고
}






int main()
{
	int n = 0;
	foo(&n);
}
