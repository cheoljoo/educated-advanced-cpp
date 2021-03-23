#include <iostream>

// nullptr
void foo(int n)   { std::cout << "int" << std::endl; }	
void foo(void* p) { std::cout << "void*" << std::endl; }
void goo(char* p) { std::cout << "goo" << std::endl; }

int main()
{
	foo(0);			
}



















