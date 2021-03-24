#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { LOG_FUNCTION_NAME(); }
	~Point()			{ LOG_FUNCTION_NAME(); }
	Point(const Point&) { LOG_FUNCTION_NAME(); }
};

void foo(int a, int b) {}

int main()
{
	// make_shared

	// thread	
}







