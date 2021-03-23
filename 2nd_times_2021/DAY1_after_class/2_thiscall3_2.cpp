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

	// �����ϰ� �ʹ�.
//	std::sort(v.begin(), v.end()); // Point �� "<" ������ �����ؾ� �Ѵ�.
	std::sort(v.begin(), v.end(), 
		[](const Point& p1, const Point& p2) {return p1.x < p2.x; }); // C++11

	// C++20 ����
	// 1. �ݺ��� ��� �����̳� ����
	// 2. ��� ����� ������ ���� ���� - "Projection" �̶�� ����.
	std::ranges::sort(v,		// �����̳�
					std::less{},// < ��������!! 
					&Point::x); // �� ����� ���ؼ�..
								// thiscall3_1 ���� Max �� �����ϰ� ����

//	Point pt(1, 2); // C++98
//	Point pt{ 1,2 };// C++11 ����

//	foo(Point(1, 2)); // foo �Լ��� Point �� �ӽð�ü ����
//	foo(Point{ 1, 2 }); // foo �Լ��� Point �� �ӽð�ü ����
//	foo(Point{}); // foo �Լ��� Point �� �ӽð�ü(���ڰ� ���� ������ ȣ��)
}
// g++ �ҽ�.cpp -std=c++20
// 11:05�� ���� �����մϴ�.

// github.com/codenuri/SOURCE �� �ҽ� �ٷιٷ� �ø��ڽ��ϴ�.


