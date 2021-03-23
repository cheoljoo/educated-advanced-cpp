#include <iostream>

struct Point
{
	int x{ 0 };
	int y{ 0 };
};

// T 타입자체에 대해서 < 연산 수행.
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
	Max(p1, p2, &Point::x ); // p1, p2 의 크기를 비교할건데..
							 // Point::x 멤버로 비교해 달라.
	Max(p1, p2, &Point::y);
}




