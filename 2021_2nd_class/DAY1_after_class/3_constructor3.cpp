#include <iostream>

// 생성자와 가상함수
// 생성자에서는 가상함수가 동작하지 않습니다... 
//			    무조건 자신의 멤버가 호출됩니다.
// 왜 이렇게 문법을 만들었을까요 ?
// C++ : 생성자에서는 가상함수 동작 안함
// C#  : 생성자에서는 가상함수 동작!!. 초기화 되지 않은 멤버를 사용할 위험 있음.
struct Base
{
	Base() { goo();  }  // 생성자에서 가상함수 호출
	void foo() { goo(); }
	virtual void goo() { std::cout << "Base::goo" << std::endl; }
};

struct Derived : public Base
{
	int x;
	Derived() : x(10) {}

	virtual void goo() override { std::cout << "Derived::goo : " << x << std::endl; }
};

int main()
{
	Derived d;
//	d.foo();
}
