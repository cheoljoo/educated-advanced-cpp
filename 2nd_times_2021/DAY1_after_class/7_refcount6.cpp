#include <iostream>
#include <vector>


template<typename T>
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

// �� �ڵ�� Truck �� �Ҹ��ڰ� ȣ����� �ʴ� ������ �ֽ��ϴ�.
class RefCount
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }

	void Release() // void Release(RefCount* this)
	{ 
		if (--refCount == 0) 
			delete this;  // �Ҹ��ڰ� �����Լ��� �ƴϸ�
						  // this �� Ÿ������ ������ �Ҹ��� ȣ��.
						  // �Ҹ��ڰ� �����Լ� ��� "this�� Ÿ���� �ƴ�" �޸𸮸� �������� ȣ��
	}
protected:
	//~RefCount() { std::cout << "~RefCount" << std::endl; }
	virtual ~RefCount() { std::cout << "~RefCount" << std::endl; }
};

class Truck : public RefCount
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	AutoPtr<Truck> p1 = new Truck;
}







