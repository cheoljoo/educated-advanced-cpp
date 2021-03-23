#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	void print() const	
	{
		x = 10;			

		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
	const Point pt(1, 2);

	pt.x = 10;		
	pt.set(10, 20);	
	pt.print();		
}


