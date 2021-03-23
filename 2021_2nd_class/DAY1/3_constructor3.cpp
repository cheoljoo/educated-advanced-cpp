#include <iostream>

// 생성자와 가상함수
struct Base
{
	Base() { goo(); }
	void foo() { goo(); }
	virtual void goo() { std::cout << "Base::goo" << std::endl; }
};

struct Derived : public Base
{
	int x;
	Derived() : x(10) {}

	virtual void goo() override { std::cout << "Derived::goo" << std::endl; }
};

int main()
{
	Derived d;
	d.foo();
}
