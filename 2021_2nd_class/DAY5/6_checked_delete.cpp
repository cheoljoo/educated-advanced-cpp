#include <iostream>


class Test
{
public:
	Test()  { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }
};

void foo(Test* p)
{
	delete p;
}

int main()
{
	Test* p = new Test;
	foo(p);
}
