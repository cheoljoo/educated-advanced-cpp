#include <iostream>

// �����ڿ� ����

struct Resource
{
	Resource() { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};
// unique_ptr �����
// �ذ�å 2. raw pointer �� ������� ����!!!. ����Ʈ �����ͷ� �����ض�.
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
	// ���α׷��� ��� ���� ����.
}
