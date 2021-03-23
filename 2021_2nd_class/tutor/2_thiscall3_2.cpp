#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>  // C++20
#include <functional>
struct Point
{
	int x{ 0 };
	int y{ 0 };
};
int main()
{
	std::vector<Point> v;
	v.emplace_back(1, 2); // v.push_back( Point(1,2))
	v.emplace_back(2, 1);
	v.emplace_back(3, 5);

	// 정렬하고 싶다.
//	std::sort(v.begin(), v.end()); // Point 가 "<" 연산이 가능해야 한다.
	std::sort(v.begin(), v.end(), 
		[](const Point& p1, const Point& p2) {return p1.x < p2.x; }); // C++11

	// C++20 부터
	// 1. 반복자 대신 컨테이너 전달
	// 2. 어느 멤버로 비교할지 전달 가능 - "Projection" 이라는 개념.
	std::ranges::sort(v,		// 컨테이너
					std::less{},// < 연산으로!! 
					&Point::x); // 이 멤버를 비교해서..
								// thiscall3_1 번의 Max 와 유사하게 구현

//	Point pt(1, 2); // C++98
//	Point pt{ 1,2 };// C++11 부터

//	foo(Point(1, 2)); // foo 함수에 Point 의 임시객체 전달
//	foo(Point{ 1, 2 }); // foo 함수에 Point 의 임시객체 전달
//	foo(Point{}); // foo 함수에 Point 의 임시객체(인자가 없는 생성자 호출)
}
// g++ 소스.cpp -std=c++20
// 11:05분 부터 시작합니다.

// github.com/codenuri/SOURCE 에 소스 바로바로 올리겠습니다.


