#include <iostream>

// (함수템플릿에서 T가 결정된후)
// 치환에 실패 한것은 에러가 아니다.

// Substitution Failure Is Not An Error => "SFINAE"
// C++11 이 아닌 예전 부터 사용되던 용어.

template<typename T>
typename T::type foo(T a)  { std::cout << "T" << std::endl; return 0; }
//     int::type foo(int a){...}


void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	// 함수 호출은 "함수 인자"를 보고 선택
	foo(3); 
}
