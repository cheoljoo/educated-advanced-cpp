#include <iostream>

// 생성자와 예외

struct Resource
{
	Resource() { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};
// unique_ptr 만들기
// 해결책 2. raw pointer 를 사용하지 말라!!!. 스마트 포인터로 변경해라.
#include <memory>

class Test
{
//	Resource* p;
	std::shared_ptr<Resource> p;
public:
	Test() : p(new Resource)
	{
		std::cout << "Test()" << std::endl;

		throw 1;  
	}
	~Test()
	{
//		delete p;
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
