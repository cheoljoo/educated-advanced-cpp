#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

//---------------------------
void f1(Point  pt) {} // call by value     : 복사본 객체 생성
void f2(Point& pt) {} // call by reference : 복사본 생성 안됨


Point pt(1, 2);
Point foo()		// return by value :  리턴용 임시객체가 생성된다.
{
	return pt; 
}
Point& goo()  // return by reference : 리턴용 임시객체를 만들지 말라.
{
	return pt;
}
Point& hoo()
{
	Point p(1, 2);
	return p; // 버그!!! 절대 지역변수는 참조 리턴하면 안됩니다.
}

int main()
{
	goo().x = 10; // ok.  임시객체가 아닌 진짜 pt.x = 10 의 의미.

	foo().x = 10; // error. 리턴용 임시객체.x = 10 인데..
					//     임시객체는 왼쪽에 올수 없다.


	Point p(0, 0);
	f1(p);
	f2(p);
}







