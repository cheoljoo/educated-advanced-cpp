#include <iostream>

// 생성자와 예외

struct Resource
{
	Resource() { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};

// 유명한 해결책 1. 생성자에서 자원 할당 하지 말라!!!
//				   예외 가능성이 있는 어떠한 코드도 작성하지 말라.
// two phase constructor 기술..
class Test
{
	Resource* p;
public:
	Test() : p(nullptr) {}

	// 자원 할당 전용 함수.
	void construct()
	{
		p = new Resource;

		throw 1;  
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
		t.construct();
	}
	catch (...) {}
	// 프로그램은 계속 실행 가능.
}
