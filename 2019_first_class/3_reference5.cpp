// 3_참조계수5.cpp
//
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class myRefCountedBase
{
	mutable int m_refCount = 0 ; 
public: 
	// 상수 객체라도 수명을 관리할수 있어야 한다.
	// 참조 계수를 조작하는 함수는 반드시 "상수 멤버함수"이어야 한다.
	void ref() const { ++m_refCount; }
	void deref() const 	// void deref( myRefCountedBase* this)
	{ 
		if(--m_refCount == 0) 
			delete static_cast<T*>(this);
	}
protected:
	~myRefCountedBase(){}
};

class Car : public myRefCountedBase<Car>
{
public:
	~Car() { cout << "~Car" << endl; }
};

class Truck : public myRefCountedBase<Truck>
{
public:
	~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	Car* p1 = new Car;
	p1->ref();
	p1->deref();

}
