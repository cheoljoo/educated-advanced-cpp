#include <iostream>

template<int N> struct int2type
{
	enum { value = N };
};

int main()
{
	foo(0);
	foo(1);

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1);
}
