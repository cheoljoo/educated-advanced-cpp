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
	void AddRef() { ++refCount; }

	void Release() // void Release(RefCount* this)
	{ 
		if (--refCount == 0) 
			delete this;  // 소멸자가 가상함수가 아니면
						  // this 의 타입정보 만으로 소멸자 호출.
						  // 소멸자가 가상함수 라면 "this의 타입이 아닌" 메모리를 조사한후 호출
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







