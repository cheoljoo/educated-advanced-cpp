#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자
//void foo(Point& pt) {} : 임시객체를 인자로 받을수 없다.!! 
void foo(const Point& pt) {} // 임시객체를 받을수 있다.

int main()
{
//	Point pt(1, 2);
//	foo(pt);

	// 임시객체를 사용한 인자 전달.
	foo(Point( 1, 2 ));
	// sort(v, std::less{}, // 이 표현이 결국 임시객체로 less를 전달.



	std::cout << "-----" << std::endl;
}

//--------------
void goo(const Point& pt) {} // call by reference
void hoo(const Point pt) {}  // call by value

int main()
{	
	Point pt(1, 2);
	goo(pt);
	hoo(pt);

	goo(Point(1, 2));

	// 아래 2줄은 미묘한 차이가 있습니다.
	Point p1(1, 2);
	Point p2{ 1, 2 };
}









