// 7_enable_if6
#include <iostream>
#include <type_traits>

template<typename T> class Point
{
	T x;
	T y;
public:
	Point(T a, T b) : x(a), y(b) {}

	// U(int)가 T(double)로 변환될수 있다면
	// Point<U> 는 Point<T> 로 변환될수 있어야 한다.

	// Point(const Point<T>& pt) : x(pt.x), y(pt.y) {} // 같은 타입만 받는다
	// Point(const Point<int>& pt) : x(pt.x), y(pt.y) {}  // Point<int> 만 받는다.

	// template 버전의 복사생성자 필요
	template<typename U>
	Point(const Point<U>& pt) : x(pt.x), y(pt.y) {}

	template<typename> friend class Point; // friend class
};

int main()
{
	Point<double> p1(2.1, 3.4);
	Point<int> p2(1, 2);

	Point<double> p3 = p1; // ok .. 복사 생성자
	Point<double> p4 = p2; // 되는게 좋을까요 ? 안되는게 좋을까요 ?
						   // Point<double> = Point<int> 가 되므로 복사 생성자 아님.
		

}