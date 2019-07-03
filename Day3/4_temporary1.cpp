/* 4_temporary1
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

int main()
{
	// Point p1(1,2);  // 이름 있는 객체. named object

	// Point(1,2);  // 임시객체. unnamed object
		// 자기를 만든 문장의 끝에서 파괴

	// Point(1,2) , std::cout << "X" << std::endl;

	// Point&& r = Point(1,2);

	const Point& r = Point(1,2);

	std::cout << "-------" << std::endl;
}
