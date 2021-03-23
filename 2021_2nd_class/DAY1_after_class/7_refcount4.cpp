#include <iostream>
#include <vector>

class Car
{
	int refCount = 0;
	int speed;
public:
	void AddRef() { ++refCount; }

	void Release() { if (--refCount == 0) delete this; }

protected:
	~Car() { std::cout << "~Car" << std::endl; }
};

// ��������� �ڵ����� ���� ���ִ� ����Ʈ ������
template<typename T> 
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr)    : obj(p)      { if (obj) obj->AddRef();  }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	// ����Ʈ �������� �⺻ -> �� * ������ ������
	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};

int main()
{
	AutoPtr<Car> p1 = new Car; // AutoPtr<Car> p1(new Car )
	AutoPtr<Car> p2 = p1;

//	p1->Car�Լ�();
//	(*p).Car�Լ�();
}




