#include <iostream>
#include <type_traits>

class Point
{
	int x;
	int y;
public:
	Point() : x{ 0 }, y{ 0 } {}
	Point(int a, int b) : x{ a }, y{ b } ()
};

int main()
{
	Point p1;
	Point p2(1, 2);

	int n = p2;
}
