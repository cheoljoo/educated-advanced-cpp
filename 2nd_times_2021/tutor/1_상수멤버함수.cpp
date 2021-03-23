#include <iostream>

class Point
{
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
	void set(int a, int b) { x = a; y = b; }

	void print()  const	// 상수 멤버 함수
	{
		//x = 10;	// error. 상수 멤버 에서는 모든 멤버를 상수 취급		

		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
	const Point pt(1, 2);

	pt.x = 10;	   // error. pt는 상수이므로	
	pt.set(10, 20);// error. 	
	pt.print();	   // error. 
		// 호출되게 하려면 print()는 상수멤버 함수이어야 합니다.

		// 핵심 : 상수 객체는 "상수 멤버 함수" 만 호출가능하다.!!
		//        위 코드에서 print()는 반드시 상수 멤버함수가 되어야 한다.
}


