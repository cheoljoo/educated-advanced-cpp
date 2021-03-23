#include <iostream>

class Point
{
	int x, y;
public:
	void set(int a, int b)  // set(Point* this,int a , int b)
	{						
		x = a;				
		y = b;				
	}						
};

int main()
{
	Point p1, p2;

	p1.set(10, 20);     // set(&p1,10,20)
	p2.set(10, 20); 
}



