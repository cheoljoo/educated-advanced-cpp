#include "cppmaster.h"

template<typename T> void foo(T&& arg)
{
}
int main()
{
	int n = 10;

	foo(n);  
	foo(10); 

	const int c = 10;
	foo(c); 
}




