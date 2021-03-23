#include <iostream>

struct A
{
	int a;
	void fa() { std::cout << "fa : " << this << std::endl; }
};
struct B
{
	int b;
	void fb() { std::cout << "fb : " << this << std::endl; }
};
struct C : public A, public B
{
	int c;
	void fc() { std::cout << "fc : " << this << std::endl; }
};
int main()
{
	void(C::*f)();

//	f = &C::fa;
	f = &C::fb;

	C obj;
	obj.fc();	// fc(&obj);

	(obj.*f)();	// 

}


