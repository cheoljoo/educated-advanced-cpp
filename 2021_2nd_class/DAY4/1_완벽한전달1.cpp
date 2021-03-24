#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

template<typename F, typename T> void chronometry(F f, T arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	foo(10);
	goo(n);

	std::cout << n << std::endl;
}
