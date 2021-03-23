#include <iostream>
#include <vector>

class Car
{
	int refCount = 0;
	int speed;
public:
	void AddRef() { ++refCount; }

	void Release() { if (--refCount == 0) delete this; }

	// protected �Ҹ��� : ��ü�� ���ÿ� ����� ���� �Ҷ� ���
protected:
	~Car() { std::cout << "~Car" << std::endl; }

	// ���� ����� ����, ���ø� �����ϰ� �Ϸ���
	// void* operator new(std::size_t sz) { return nullptr; } // C++ Idioms 71�����
};

int main()
{
//	Car c; // ���� ��ü. �ı��� �Ҹ��ڸ� ȣ���ؾ� �ϴµ�
			// �Ҹ��ڰ� protected�� �ִ�.

	Car* p1 = new Car;
	p1->AddRef();  
	Car* p2 = p1;
	p2->AddRef();  

	p2->Release(); 
	std::cout << "-------------------" << std::endl;
	p1->Release(); 
}




