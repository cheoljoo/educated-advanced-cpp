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
	// 아래 주석같은 코드가 10곳에 있는데.. 
	// 메모리 할당 방식을 "operator new()" 대신 "malloc" 으로 변경하려고 한다면 ?

	//Point* p1 = static_cast<Point*>(operator new(sizeof(Point)));
	//new(p1) Point(1, 2);
	//p1->~Point();
	//operator delete(p1);

	// allocator : 메모리 할당기. 메모리 할당/해제를 책임지는 클래스
	//				C++98 부터...~~

	std::allocator<Point> ax; // Point 타입의 메모리 할당기!
							// 표준 할당기는 "operator new()", "operator delete()" 사용

	Point* p1 = ax.allocate(1); // Point 한개 할당
	
	ax.construct(p1, 1, 2);		// 생성자 호출

	ax.destroy(p1);				// 소멸자 호출
	
	ax.deallocate(p1, 1);		// 메모리 해지

}