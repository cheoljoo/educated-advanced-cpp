#include "cppmaster.h"
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b) { LOG_FUNCTION_NAME(); }
	~Point()            { LOG_FUNCTION_NAME(); }
	Point(const Point&) { LOG_FUNCTION_NAME(); }
};
int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// 1. 
	Point pt(1, 2);
	v.push_back(pt);

	std::cout << "-----" << std::endl;
}




