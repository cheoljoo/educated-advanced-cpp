// 1번 복사해오세요
#include <iostream>
#include <type_traits>



template<typename T> void printv(const T& v)
{
	// if : 컴파일시 false 가 되어도
	//		"템플릿 ==> C++함수" 가 생성된다.(인스턴스화)
	/*
	if ( std::is_pointer_v<T> ) // if ( false )
		std::cout << v << " : " << *v << std::endl; // 이 부분도 C++ 함수로 생성
	else
		std::cout << v << std::endl;
	*/

	// if constexpr : 조건이 false 일때는 해당 문장을 인스턴스화 하지 말라는 의미!
	// C++17
	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl; 
	else
		std::cout << v << std::endl;
}
// *v 가 에러가 나오는 현상에 대한 해결책.
// 1. integral_constant - C++11
// 2. enable_if         - C++11
// 3. if constexpr      - C++17 - 위 코드 참고
// 4. concept           - C++20




int main()
{
	int n = 10;

	printv(n); // 이 경우에 . error
}

