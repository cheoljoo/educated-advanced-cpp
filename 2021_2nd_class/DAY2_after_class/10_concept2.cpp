// 10_concept2
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <concepts> // 이 안에 concept1 에서 만든 "Addable" 같은 표준 concept이 있습니다.

template<typename IT, typename T> requires (! std::predicate<T, std::iter_value_t<IT> > )
void find(IT first, IT last, T value)
{
	std::cout << "값 버전" << std::endl;
}

// predicate<F, 타입> : F라는 함수 타입이 "타입"을 인자로 받을수 있는가 ?
// iter_value_t<반복자> : 반복자가 가리키는 요소의 타입..
//						IT::value_type => C++98 표기

template<typename IT, typename T> requires std::predicate<T, std::iter_value_t<IT> >
void find(IT first, IT last, T func) 
{
	std::cout << "함수 전달 버전" << std::endl;
}

bool foo(int) { return true; }

int main()
{
	// STL 의 현재
	//std::find(first, last, 30); // 값 (30) 찾기
	//std::find_if(first, last, foo); // 조건 검색(foo 함수에 차례대로 요소 전달)

	// STL의 미래
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	find(x, x+10, 30); // 값 (30) 찾기
	find(x, x + 10, foo); // 조건 검색(foo 함수에 차례대로 요소 전달)

}

