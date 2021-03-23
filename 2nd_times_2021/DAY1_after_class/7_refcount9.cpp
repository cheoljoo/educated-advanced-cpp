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

// Ŭ���� ���ø� ����� Ÿ�� ���� T�� ������� ���� ��� �Լ���
// ���ø��� �ƴ� ��� Ŭ������ �����ؼ� ��ӹް� ����.
// "thin template" �Ǵ� "template hoisting" �̶�� �̸��� ���� ���
class RefCountBase
{
protected:
	mutable int refCount = 0; 		
public:
	void AddRef()  const { ++refCount; }

protected:
	~RefCountBase() { std::cout << "~RefCountBase" << std::endl; }
};

template<typename T>
class RefCount : public RefCountBase
{					  
public:	
	void Release() const
	{
		if (--refCount == 0)
			delete static_cast<const T*>(this);
	}
};
class Car   : public RefCount< Car > {};
class Truck : public RefCount< Truck >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	AutoPtr<Truck> p = new Truck;

}







