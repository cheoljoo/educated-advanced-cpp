#include <iostream>

class Empty
{
};

struct Data
{
	Empty e;
	int   n;
};

int main()
{
	Data d;
	std::cout << sizeof(d) << std::endl; 
}





