#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	Point()				: x(0), y(0) { LOG_FUNCTION_NAME(); }
	Point(int a, int b) : x(a), y(b) { LOG_FUNCTION_NAME(); }
	~Point()						 { LOG_FUNCTION_NAME(); }
};

int main()
{
	// new
	// 1. 메모리 할당
	// 2. 생성자 호출
	// Point* p1 = new Point(1, 2);

	// delete
	// 1. 소멸자 호출
	// 2. 메모리 해지
	// delete p1;

	// 1. 메모리만 할당
	Point* p1 = static_cast<Point*>(operator new(sizeof(Point))); // malloc(sizeof(Point))

	// 2. 할당된 메모리에 생성자 호출
	new(p1) Point(1, 2);	// "placement new" 라고 부릅니다.
							// C++20: std::construct_at( p1, 1, 2)

	// 3. 메모리 해지 없이 소멸자 호출
	p1->~Point();		//  C++17 : std::destroy_at( p1 ); 


	// 4. 메모리만 해지
	operator delete(p1);
}
// malloc : 메모리 할당
// new    : 객체 생성 ( 메모리 할당 + 생성자 호출 )

// new    Point(1,2) : 새로운 메모리에 객체를 생성해 달라.
// new(p) Point(1,2) : 이미 할당된 메모리 주소 p에 객체를 생성(생성자를 호출)해 달라.