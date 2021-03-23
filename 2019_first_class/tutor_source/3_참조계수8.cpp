// 3_참조계수1.cpp
#include <iostream>
#include <vector>


class RefCountedBase
{
protected:
	mutable int m_refCount = 0;
public:
	void ref()   const { ++m_refCount; }
};

#define WTF_MAKE_NONCOPYABLE(classname )		\
		classname(const classname&)= delete;	\
		classname& operator=(const classname&) = delete;

template<typename T> class RefCounted : public RefCountedBase
{
	// 이 클래스(또는 기반 클래스는)는 복사 되면 안된다.
	// 컴파일러가 복사 생성자를 만들지 못하게 한다.
	//RefCounted(const RefCounted&) = delete; // C++11 함수 삭제
	//RefCounted& operator=(const RefCounted&) = delete; //대입도삭제
	
	WTF_MAKE_NONCOPYABLE(RefCounted)
protected:
	RefCounted() {}
public:
	void deref() const
	{
		if (--m_refCount == 0) delete static_cast<const T*>(this);
	}
protected:
	~RefCounted() {  }
};
class Car : public RefCounted<Car>
{
public:
	Car() {}
	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
	Car* p1 = new Car;	p1->ref();
	Car* p2 = p1;   	p2->ref();

	//Car* p3 = new Car(*p1); // ???

	p2->deref();
	p1->deref();
}

