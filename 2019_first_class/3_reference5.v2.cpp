// 3_참조계수5.cpp
//
#include <stdio.h>
#include <iostream>
#include <vector>

template <typename T>
class RefCountedBase
{
        mutable int m_refCount = 0 ;
public:
        // 상수 객체라도 수명을 관리할수 있어야 한다.
        // 참조 계수를 조작하는 함수는 반드시 "상수 멤버함수"이어야 한다.
		void ref() const { ++m_refCount; }
		void deref() const      // void deref( RefCountedBase* this)
		{
			// 일반 멤버 함수에서 this : RefCountedBase* this
			// 상수 멤버 함수에서 this : const RefCountedBase* this
			if(--m_refCount == ){
				// delete static_cast(T*)(this);    // error
				delete static_cast<T*>(
						const_cast<RefCountedBase*>(this));
				//delete static_cast<const T*>(this); // ok : 이 모양도 가능하다. this가 const이니 맞춰준다. const T*도 delete가 된다.
			}
protected:
        ~RefCountedBase(){}
};

class Car : public RefCountedBase<Car>
{
public:
        ~Car() { std::cout << "~Car" << std::endl; }
};

class Truck : public RefCountedBase<Truck>
{
public:
        ~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
        Car* p1 = new Car;
        p1->ref();
        p1->deref();


