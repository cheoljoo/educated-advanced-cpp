
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	Point pt(1, 2);
	
	pt.x = 10;			
	Point(1, 2).x = 10;	
						

	Point* p1 = &pt;			
	Point* p2 = &Point(1, 2);	
							

	Point& r1 = pt;			
	Point& r2 = Point(1, 2);
}





