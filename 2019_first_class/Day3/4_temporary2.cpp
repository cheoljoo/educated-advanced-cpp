/* 4_temporary2
-  임시객체의 특징
*/

#include <iostream>
//using namespace std;

/*
- 
*/

struct Point
{
	int x,y;
	Point(int a=0 , int b=0) : x(a), y(b) 
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual ~Point()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

int main()
{
	Point pt(0,0);
	pt.x = 10; // ok

	Point(0,0).x = 10; //  임시객체는 왼쪽에 올수 없다. 
			  // 임시객체는 rvalue이다. 

	Point* p1 = &pt; 		// ok 
	// Point* p2 = &Point(0,0);	// error. rvalue는 주소를 구할수 없다. 

	Point& p1 = pt;			// ok 
	// Point& p2 = Point(0,0);		// error . 이렇게 해도 수명 연장이 되지 않는다. 

	// const lvalue reference는 lvalue와 rvalue를 모두 가리킨다.
	const Point& r3 = Point(0,0);		// 수명도 연장된다. 
	// r3.x = 10 // error  : 상수성이 추가됨.

	Point&& r4 = Point(0,0);
	r4.x = 10; // ok
}
