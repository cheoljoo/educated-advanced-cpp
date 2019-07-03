/* 4_temporary4
-
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

// call by value : 복사본이 생성
void foo(Point p){}

Point pt(0,0);

// return by value : 복사본 생성
// 리턴용 임시객체 생성
Point goo() { return pt; }

Point& hoo() { return pt; }	// 임시객체를 만들지 말라는 의도

int main()
{
	// Point p(1,2);
	// foo(p);

	//goo().x = 10;  // error : return value이므로 임시객체
	goo();

	hoo().x = 10; // ok..

	std::cout << "-------"  << std::endl;
}
