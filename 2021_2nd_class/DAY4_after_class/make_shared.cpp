#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {  }
};

int main()
{
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);

	// make_shared 의 대표적인 2가지 장점
	// 1. 메모리의 효율성( 객체 + 관리객체를 한번에 할당)
	// 2. 예외 안정성
	// 자원의 할당과, 자원 관리객체의 생성은 반드시 한번에 이루어져야 안전하다.
	// foo( std::shared_ptr<Point>(new Point(1, 2)), goo() );

	// std::make_shared<Point>(1, 2) : Point 객체 생성과 shared_ptr 생성이 
	//								하나의 함수로 처리.

	foo(std::make_shared<Point>(1, 2), goo());

	// RAII : Resource Acquision Is Initialization
	//     자원의 획득의 "자원관리객체가" 초기화 될때 이다.
}

void foo(std::shared_ptr<Point> sp, int a ) {}

int goo() { return 0; }






// 오후 수업은 13:00 부터 진행합니다.

