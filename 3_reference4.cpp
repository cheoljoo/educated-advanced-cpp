// 3_참조계수4.cpp
// open source를 만든느 사람들이 virtual 붙여서 overhead를 만드는 것을 싫어한다.
//
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// CRTP (Curiosly Recurring Templae Pattern) - 71 page
// 기반 클래스가 템플릿인데, 파생 클래스를 만들때 자신의 이름을
// 템플릿 인자로 전달해주는 기술.
// 미래에 만들어질 파생클래스의 이름을 미리 사용할수 있다. 
// ex) 가상 함수를 사라지게 하다.   속도도 느리지 않고 , (virtual 사용하지 않음)
template <typename T>
class myRefCountedBase
{
	int m_refCount = 0 ; 
public: 
	void ref() { ++m_refCount; }
	void deref()	// void deref( myRefCountedBase* this)
	{ 
		if(--m_refCount == 0) 
			//delete static_cast<Car*>(this); 		// 이런 경우 Car를 모르므로 error
					// 그래서 template으로 변환
			delete static_cast<T*>(this);	// ok
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
	p1->ref(); 	// 규칙 1 . 객체 생성시 참조 계수 증가

	Car* p2 = p1;
	p2->ref(); 	// 규칙 2 . 포인터 복사시 참조계수 증가

	p2->deref(); 	// 규칙 3 . 더이상 필요없을때 참조계수 감소
	p1->deref(); 	// 규칙 3 . 더이상 필요없을때 참조계수 감소

}
