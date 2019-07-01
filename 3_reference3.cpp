// 3_참조계수3.cpp
// delete를 할 시점을 잡는게 힘들다. 
//
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class myRefCountedBase
{
	int m_refCount = 0 ; 
public: 
	void ref() { ++m_refCount; }
	void deref()	// void deref( myRefCountedBase* this)
	{ 
		if(--m_refCount == 0) delete this; 
	}
protected:
	// 핵심 기반 클래스 포인터로 delete하면 기반 클래스의 소멸자만 호출된다.
	// 파생클래스 소멸자를 호출되게 하려면 viraul destructor를 사용해야 한다. - C++ 기본 문법
	virtual ~myRefCountedBase(){}
};

class Car : public myRefCountedBase
{
public:
	virtual ~Car() { cout << "~Car" << endl; }
};

class Truck : public myRefCountedBase 
{
public:
	virtual ~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	Car* p1 = new Car;
	p1->ref(); 	// 규칙 1 . 객체 생성시 참조 계수 증가

	Car* p2 = p1;
	p2->ref(); 	// 규칙 2 . 포인터 복사시 참조계수 증가

	p2->deref(); 	// 규칙 3 . 더이상 필요없을때 참조계수 감소
	p1->deref(); 	// 규칙 3 . 더이상 필요없을때 참조계수 감소

}
