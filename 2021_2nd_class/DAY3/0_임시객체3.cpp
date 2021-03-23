#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};


void foo(const Point& pt) {}

int main()
{
	Point pt(1, 2);
	foo(pt);

	std::cout << "-----" << std::endl;
}





