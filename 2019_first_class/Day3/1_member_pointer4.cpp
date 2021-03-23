/* 1_member_pointer4
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
	double z;
};

int main()
{
	// 멤버 테이타를 위한 포인터
	int n= 0;
	int* p1 = &n;
	int Point::*p2 = &Point::y;	// 구조체 안에서 y의 위치 (Offset = 4)

	Point pt;
	pt.*p2 = 10;	// *( ((char*)&pt) + p2 ) = 10

	printf("%d\n",p2);	// 4 
	printf("%d\n",pt.y);	// 10 

	//p2 = p2 + 1;	// error. 멤버테이터를 가리키는 포인터는 사칙연산이 안됨
}
