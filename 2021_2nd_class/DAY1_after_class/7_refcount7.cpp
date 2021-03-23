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

// CRTP ( Curiosly Recurring Template Pattern )
// ��� Ŭ���� ����� �Ļ� Ŭ������ �̸��� ���ø� ���ڷ� ���� �޾Ƽ� ����ϴ� ���
template<typename T> 
class RefCount
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }

	void Release() 
	{
		if (--refCount == 0)
			delete static_cast<T*>(this);  
	}
protected:
	~RefCount() { std::cout << "~RefCount" << std::endl; }
};


class Truck : public RefCount< Truck > 
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	AutoPtr<Truck> p1 = new Truck;
}







