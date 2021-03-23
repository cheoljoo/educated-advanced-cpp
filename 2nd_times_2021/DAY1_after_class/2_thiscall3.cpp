#include <iostream>

// 멤버 변수 포인터
struct Point
{
	int x{ 0 }; // C++11 부터 가능.
	int y{ 0 };
};

int main()
{
	int n = 0;
	int* p1 = &n; // 일반 변수의 포인터!!

	//void(Point::*f)(int); // 멤버 함수 포인터

	int Point::*p2 = &Point::x; // 멤버 변수의 포인터
	int Point::*p3 = &Point::y; // 핵심 : 그런데!!! Point 객체를 만든적이 없다
								// Point 안에서 y 멤버가 얼마나 떨어져 있는가?
								// 4
								// C언어의 "offsetof(Point, y)" 의미
	//std::cout << p3 << std::endl; // 1  왜 1일까 ?
	printf("%d\n", p3);  // 4 

//	*p3 = 100; // 될까 ?? error. 아직 객체가 없다. p3는 offset 4 일뿐이다.

	Point pt;
	pt.y = 100;
	pt.*p3 = 200;  // 위 코드와 동일한 의미.

	std::cout << pt.y << std::endl; // 200
}




