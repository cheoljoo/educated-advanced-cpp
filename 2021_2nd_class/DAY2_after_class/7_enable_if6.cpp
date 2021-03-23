// 7_enable_if6
#include <iostream>
#include <type_traits>

template<typename T> class Point
{
	T x;
	T y;
public:
	Point(T a, T b) : x(a), y(b) {}

	// U(int)�� T(double)�� ��ȯ�ɼ� �ִٸ�
	// Point<U> �� Point<T> �� ��ȯ�ɼ� �־�� �Ѵ�.

	// Point(const Point<T>& pt) : x(pt.x), y(pt.y) {} // ���� Ÿ�Ը� �޴´�
	// Point(const Point<int>& pt) : x(pt.x), y(pt.y) {}  // Point<int> �� �޴´�.

	// template ������ ��������� �ʿ�
	template<typename U>
	Point(const Point<U>& pt) : x(pt.x), y(pt.y) {}

	template<typename> friend class Point; // friend class
};

int main()
{
	Point<double> p1(2.1, 3.4);
	Point<int> p2(1, 2);

	Point<double> p3 = p1; // ok .. ���� ������
	Point<double> p4 = p2; // �Ǵ°� ������� ? �ȵǴ°� ������� ?
						   // Point<double> = Point<int> �� �ǹǷ� ���� ������ �ƴ�.
		

}