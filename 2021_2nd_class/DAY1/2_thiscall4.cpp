#include <iostream>

// 가상함수의 멤버 함수 포인터

class Shape
{
public:
	virtual void Draw() const = 0;
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
	void(Shape::*f)() const = &Shape::Draw;

	Rect r;
	(r.*f)();

	Circle c;
	(c.*f)();
}
