// 11_range
#include <iostream>
#include <vector>
#include <ranges> // C++20 헤더

// C++20 에는 RANGE 라는 새로운 형태의 STL 이 등장합니다.
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9 };


	// r 이 내부적으로 v의 참조와, 필터 함수들을 보관하고 있다가.!!!
	// 순회 할때 v의 모든 요소에 필터 함수 적용
	auto r = v | std::ranges::views::filter([](int a) { return a % 2 == 0; })
			   | std::ranges::views::take(3);

	v[0] = 100;

	// r에서 요소를 꺼낼때 연산 적용 - "지연된 실행"
	for (auto n : r)
		std::cout << n << std::endl;

	// range 는 사실 아주 간단한 도구일뿐입니다.
	std::ranges::take_view tv(v, 3); // 내부적으로 v참조를 보관하다가 3개까지면 꺼내줌
	std::ranges::filter_view fv(tv, [](int a) { return a % 2 == 0; });
	
	
//	auto r2 = v | std::ranges::views::take(3); // 이코드가 위와 동일

	for (auto n : fv)
		std::cout << n << std::endl;		   

	
}

// 오늘 모든 수업소스는 cafe.naver.com/cppmaster 에 올리겠습니다.



