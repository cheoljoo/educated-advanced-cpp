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

		// 생성자는 반환값이 없습니다.
		// 외부에 실패를 알릴때 예외를 사용하는 경우가 있습니다.
		throw 1;  // 생성자가 예외가 있으면 "생성자 호출에 실패" 했다고 생각되어서
				  // 소멸자가 호출되지 않습니다.
				  // 자원 누수의 가능성을 생각해야 합니다.
	}
	~Test() 
	{ 
		delete p;
		std::cout << "~Test()" << std::endl;
	}
};
int main()
{
	try
	{
		Test t;
	}
	catch (...) {}
	// 프로그램은 계속 실행 가능.
}
