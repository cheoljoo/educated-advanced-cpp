#include <iostream>

// �����ڿ� ����

struct Resource
{
	Resource() { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};

// ������ �ذ�å 1. �����ڿ��� �ڿ� �Ҵ� ���� ����!!!
//				   ���� ���ɼ��� �ִ� ��� �ڵ嵵 �ۼ����� ����.
// two phase constructor ���..
class Test
{
	Resource* p;
public:
	Test() : p(nullptr) {}

	// �ڿ� �Ҵ� ���� �Լ�.
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
	// ���α׷��� ��� ���� ����.
}
