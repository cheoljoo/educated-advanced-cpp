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
	C obj;
	A* pA = &obj;
	B* pB = &obj;
	std::cout << &obj << std::endl;
	std::cout << pA << std::endl;
	std::cout << pB << std::endl;

	obj.fc();
	obj.fa();
	obj.fb();
}




