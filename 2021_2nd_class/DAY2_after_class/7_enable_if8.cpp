#include <iostream>
#include <type_traits>

template<typename T> class Point
{
	T x;
	T y;
public:
	Point(T a, T b) : x(a), y(b) {}

	// U�� T �� �Ͻ��� ��ȯ�� ������ ��츸 "���� �����ڸ� ����� �ϴ� ���� �����ϴ�."
	// �ٽ� : �����ڴ� ���� Ÿ���� ���� ������ enable_if �� ���� Ÿ���ڸ��� ������ �����ϴ�.
	//        �̷����� ��κ� "���ø� ����"�� Ȱ�� �մϴ�.
	/*
	template<typename U>
	std::enable_if_t< std::is_convertible_v<U, T> > // error. �����ڴ� ���� Ÿ���� ����.
	Point(const Point<U>& pt) : x(pt.x), y(pt.y) {}
	*/
	template<typename U,
			 typename V = std::enable_if_t< std::is_convertible_v<U, T> > >	
						// std::enable_if< std::is_convertible_v<U, T> >::type >	
	Point(const Point<U>& pt) : x(pt.x), y(pt.y) {}


	template<typename> friend class Point;
};


int main()
{
	Point<double> p1(2.1, 3.4);
	Point<int> p2(1, 2);

	Point<double> p3 = p1;
	Point<double> p4 = p2;

	Point<int*> p5 = p1; // 
}

