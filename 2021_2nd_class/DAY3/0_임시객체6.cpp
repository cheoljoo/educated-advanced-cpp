#include <iostream>

class Test
{
public:
	void foo() { std::cout << "foo" << std::endl; }
};

int main()
{
	Test t;
	t.foo();

	Test().foo();
}
