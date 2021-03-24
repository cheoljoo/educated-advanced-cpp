#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	Point()				: x(0), y(0) { LOG_FUNCTION_NAME(); }
	Point(int a, int b) : x(a), y(b) { LOG_FUNCTION_NAME(); }
	~Point() { LOG_FUNCTION_NAME(); }
};

int main()
{
	//Point* p1 = static_cast<Point*>(operator new(sizeof(Point)));
	//new(p1) Point(1, 2);
	//p1->~Point();
	//operator delete(p1);

	std::allocator<Point> ax;

	Point* p1 = ax.allocate(1);
	ax.construct(p1, 1, 2);
	ax.destroy(p1);
	ax.deallocate(p1, 1);

}