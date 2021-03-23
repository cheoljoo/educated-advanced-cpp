/* 4_temporary6
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

	// 복사 생성자 모양 1 . call by value
	// 복사 생성자를 무한히 호출하는 표현 - error
	// Point(Point p){} // Point p = p1
			// 인자를 부르는데 , 또 부른다.  무한루프므로 error
	// 2. 참조 사용
	// rvalue를 받을수 없다. 즉 , 값을 반환하는 함수의 반환값을 받을수 없다.
	//Point(Point& p){}	// Point& p = p1

	// 3. const lvalue reference
	// lvalue 와 rvalue를 모두 받을수 있다. 
	Point(const Point& p) {
		std::cout << "lvalue 일대 복사 생성자"  << std::endl;
	}
	Point(Point&& p) {
		std::cout << "rvalue일때. Move 생성자"  << std::endl;
	}

};

Point goo()
{
	Point pt;
	return pt;
}

int main()
{
	Point p1;
	Point p2(1,2);
	Point p3(p1);	// Poitn(Point) 생성자가 필요하다. 

	Point p5 = Point(0,0);
	Point p4 = goo();   // Point p4 (goo() ); 
			// rvalue인 goo()은 Point& p 로 받지 못한다. 
			// 2.참조사용이 문제가 되는 경우 
	// 최적화를 하기때문에 move가 아닌 기본 constructor를 부른다.
	//  -fno-elide-constructors 을 넣으면 최적화를 하지 않으므로 Move가 print된다. 
}
