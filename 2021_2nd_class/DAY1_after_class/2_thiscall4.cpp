#include <iostream>

// 가상함수의 멤버 함수 포인터

class Shape
{
public:
	virtual void Draw() const = 0; // 순수 가상 함수
};
class Rect : public Shape
{
public:
	void Draw() const override { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() const override { std::cout << "Draw Circle" << std::endl; }
};
int main()
{
	void(Shape::*f)() const = &Shape::Draw; // 가상함수의 함수 포인터는 실제 함수 주소가 아니라
									// 가상함수 테이블에서 해당 가상함수가 몇번째 있는지의 정보

	Rect r;
	(r.*f)();  // rect 객체의 가상함수 테이블[index f]() 호출

	Circle c;
	(c.*f)(); // circle 객체의 가상함수 테이블[index f]() 호출
}
