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

template<typename T>
class RefCount
{
	mutable int refCount = 0; // mutable 멤버 데이타
						      // 상수 멤버 함수안에서도 값을 변경할수 있게 해달라.
public:
	// 참조계수를 증가/감소 하는 함수는 상수 멤버 함수가 되어야 합니다.
	// 상수객체라도 수명관리는 할수 있어야 합니다.
	void AddRef()  const { ++refCount; }

	// 상수 멤버 함수안에서의 this는 "const 타입* this" 입니다.
	void Release() const  // Release( const RefCount* this )
	{
		//x = 10; // this->x = 10;  여기서 this 타입이 const RefCount 라서 error. 

		if (--refCount == 0)
			// delete static_cast<T*>(this); // ?? 컴파일 에러
			// static_cast<Truck*>(const RefCount* this ) 모양
			// delete static_cast<T*>( const_cast<RefCount*>(this) ); // 이렇게 하거나!
			delete static_cast<const T*>(this); // 이렇게도 가능
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
	const Truck* p = new Truck;

	p->AddRef(); // 되야 할까요 ? 안되야 할까 ?
	p->Release();
}







