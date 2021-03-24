// C++ 기본에서 배우는 복사 생성자를 완벽히 이해해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자를 만들어 봅시다.
	// 1. call by value :  복사 생성자가 무한히 호출되는 모양
	//						컴파일 에러
	// Point(Point pt) {} // Point pt = p2 의 모양으로 인자 전달
					   // Point pt(p2) 의 모양!

	// 2. call by reference : 임시객체를 받을수 없다.
	//							값타입으로 리턴하는 함수의 결과를 받을수 없다.
	//Point(Point& pt) {}

	// 3. lvalue 와 rvalue를 모두 받을수 있는 유일한 방법 - const Point&
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};
Point foo()
{
	Point pt(1, 2);
	return pt;
}
int main()
{
	Point p1;		// 1번 생성자 호출
	Point p2(1, 2); // 2번 생성자 호출
	Point p3(p2);	// 인자가 한개인 생성자 필요
					// 컴파일러가 만들어 주는 복사 생성자 사용 Point(const Point&)

	Point ret = foo(); // Point ret( foo() );
}


