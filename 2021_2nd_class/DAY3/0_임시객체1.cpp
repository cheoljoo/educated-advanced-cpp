#include <iostream>
#include <type_traits>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
	Point pt(1, 2); 

	std::cout << "-------" << std::endl;

}





