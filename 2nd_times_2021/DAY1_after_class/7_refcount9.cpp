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

// 클래스 템플릿 설계시 타입 인자 T를 사용하지 않은 멤버 함수는
// 템플릿이 아닌 기반 클래스를 설계해서 상속받게 하자.
// "thin template" 또는 "template hoisting" 이라는 이름을 가진 기술
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







