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

// 이 코드는 Truck 의 소멸자가 호출되지 않는 문제가 있습니다.
class RefCount
{
	int refCount = 0;
public:
	void AddRef()  { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }
protected:
	~RefCount() { std::cout << "~RefCount" << std::endl; }
};

class Truck : public RefCount
{
	// 참조계수 관련 코드가 있어야 합니다.
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	// Truck 도 AutoPtr로 관리하고 싶습니다.
	// Truck 안에 AddRef()와  Release()가 있어야 합니다.
	AutoPtr<Truck> p1 = new Truck;
}







