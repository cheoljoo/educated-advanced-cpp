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

// 참조계수를 자동으로 관리 해주는 스마트 포인터
template<typename T> 
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr)    : obj(p)      { if (obj) obj->AddRef();  }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	// 스마트 포인터의 기본 -> 와 * 연산자 재정의
	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};

int main()
{
	AutoPtr<Car> p1 = new Car; // AutoPtr<Car> p1(new Car )
	AutoPtr<Car> p2 = p1;

//	p1->Car함수();
//	(*p).Car함수();
}




