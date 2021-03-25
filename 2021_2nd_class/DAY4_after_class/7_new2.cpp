#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
//	Point() : x(0), y(0) { LOG_FUNCTION_NAME(); }
	Point(int a, int b) : x(a), y(b) { LOG_FUNCTION_NAME(); }
	~Point() { LOG_FUNCTION_NAME(); }
};

int main()
{
	// 힙에 Point 한개를 만들어 보세요
	Point* p1 = new Point(0, 0);

	// 힙에 Point 10개를 만들어 보세요
	//Point* p2 = new Point[10];  // 디폴트 생성자가 10번 호출되야 하는데
								// 디폴트 생성자가 없습니다.

	// 메모리할당과 생성자 호출을 분리하면 편리합니다
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 할당된 메모리에 객체를 생성합니다.
	for (int i = 0; i < 10; i++)
	{
		new( &p3[i] ) Point(0, 0);
	}

	for (int i = 0; i < 10; i++)
		p3[i].~Point();

	operator delete(p3);

//	Point* p[10];
//	p[0] = new Point(0, 0);
}




