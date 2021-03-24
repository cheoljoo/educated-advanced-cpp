
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	Point pt(1, 2);
	
	pt.x = 10;			// ok		
//	Point(1, 2).x = 10;	// error. 임시객체는 =의 왼쪽에 올수 없다.
						// lvalue가 될수 없다.						

	Point* p1 = &pt;	// ok		
//	Point* p2 = &Point(1, 2);// error. 주소 연산자로 주소를 구할수 없다.

	Point& r1 = pt;		// ok		
//	Point& r2 = Point(1, 2); // error. 임시객체는 참조로 가리킬수 없다.

	const Point& r3 = Point(1, 2); // ok. const 참조로는 가리킬수 있다.
							// 이제 임시객체의 수명은 r3의 수명과 동일합니다.
							// "temporary maturization" - C++17 의 용어
	// 문제점 : 임시객체를 가리킬수 있지만 상수성이 추가되어서 가리킨다.
	//          값을 변경할수 없다.
	//r3.x = 10; // error. 상수!!

	// C++11을 만들때 임시객체라도 값을 변경하고 싶었다 -> move 만들떄(오후!!)
	Point&& r4 = Point(1, 2); // 상수성이 없이 가리킨다.
	r4.x = 10; // ok

}





