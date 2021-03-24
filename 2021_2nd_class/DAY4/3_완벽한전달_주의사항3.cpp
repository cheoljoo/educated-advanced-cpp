#include <iostream>
#include <functional>

void foo(int a, int& b) { b = 100; }


int main()
{
	int n = 10;
	std::function<void(int)> f;

	f = foo;

	f(0);

	std::cout << n << std::endl;
}