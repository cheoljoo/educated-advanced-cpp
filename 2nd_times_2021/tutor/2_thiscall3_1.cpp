#include <iostream>

struct Point
{
	int x{ 0 };
	int y{ 0 };
};

// T Ÿ����ü�� ���ؼ� < ���� ����.
template<typename T> T Max(T a, T b)
{
	return a < b ? b : a;
}

template<typename T, typename T2> T Max(T a, T b, T2 T::*p )
{
	// T  : Point
	// T2 : int

	T2& r1 = a.*p; // p1.x 
	T2& r2 = b.*p; // p2.x 

	return r1 < r2 ? b : a;
}

int main()
{
	Point p1, p2;
	Max(p1, p2, &Point::x ); // p1, p2 �� ũ�⸦ ���Ұǵ�..
							 // Point::x ����� ���� �޶�.
	Max(p1, p2, &Point::y);
}




