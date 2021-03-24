#include <iostream>

// 핵심 
// 평가되지 않은 표현식(unevaluated expression)

int foo(int a, int b); // { return 0; }

int main()
{
	int a = 0;

	int n1 = sizeof(a);		
	int n2 = sizeof(int);	
	int n3 = sizeof(&foo);	
}








