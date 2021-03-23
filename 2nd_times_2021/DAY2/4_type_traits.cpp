#include <iostream>

template<typename T> void printv(const T& v)
{
	std::cout << v << std::endl;
}
int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

