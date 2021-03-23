#include <iostream>

struct BM	
{
	BM()  { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};
struct DM
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};
struct Base
{
	BM bm;
	Base()  
	{
		std::cout << "Base()" << std::endl; 
	}
	~Base() { std::cout << "~Base()" << std::endl; }
};
struct Derived : public Base
{
	DM dm;
	Derived()  
	{
		std::cout << "Derived()" << std::endl; 
	}
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
	Derived d;
}
