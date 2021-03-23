#include <iostream>
#include <type_traits>

template<typename T> class Point
{
	T x;
	T y;
public:
	Point(T a, T b) : x(a), y(b) {}

	template<typename U>
	Point(const Point<U>& pt) : x(pt.x), y(pt.y) {}

	template<typename> friend class Point; // friend class
};
int main()
{
	Point<double> p1(2.1, 3.4);
	Point<int> p2(1, 2);

	Point<double> p3 = p1; 
	Point<double> p4 = p2; 

	Point<int*> p5 = p1; // �Ǵ°� ������� ? �ȵǴ°� ������� ?
  						 // ������ �ȵ����� �����޼��� Ȯ���� ������.
}

