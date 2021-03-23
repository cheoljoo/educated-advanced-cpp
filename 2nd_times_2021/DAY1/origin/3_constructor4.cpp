#include <iostream>

// 생성자와 예외

struct Resource
{
	Resource()  { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};

class Test
{
	Resource* p;
public:
	Test() : p(new Resource)
	{
		std::cout << "Test()" << std::endl;
	}
	~Test() 
	{ 
		delete p;
		std::cout << "~Test()" << std::endl;
	}
};
int main()
{
	Test t;
}
