// 3_참조계수9.cpp
//
#include <stdio.h>
#include <iostream>
#include <vector>


class RefCountedBase
{
protected:
        mutable int m_refCount = 0 ;
public:
		void ref() const { ++m_refCount; }
};


#define WTF_MAKE_NONCOPYABLE(classname) \
    classname(const classname&) = delete; \
    classname& operator=(const classname&) = delete;
template <typename T>
class RefCounted : public RefCountedBase
{
    WTF_MAKE_NONCOPYABLE(RefCounted);
public:
    void deref() const      // void deref( RefCounted* this)
    {
        if(--m_refCount == 0){
            delete static_cast<const T*>(this); // ok : 이 모양도 가능하다. this가 const이니 맞춰준다. const T*도 delete가 된다.
        }
    }
protected:
    RefCounted() {}
    ~RefCounted(){}
};

class Car : public RefCounted<Car>
{
    public:
        Car(){}
        ~Car() { std::cout << "~Car" << std::endl; }
        void Go(){ std::cout << "Car::Go" << std::endl; }
};

class Truck : public RefCounted<Truck>
{
    public:
        Truck(){}
        ~Truck() { std::cout << "~Truck" << std::endl; }
};

template<typename T> class AutoPtr
{
    T* m_obj;
public:
    AutoPtr(T* p=0):m_obj(p)
    {
        if(m_obj) m_obj->ref();
    }
    AutoPtr(const AutoPtr& p):m_obj(p.m_obj)
    {
        if(m_obj) m_obj->ref();
    }
    ~AutoPtr()
    {
        if(m_obj) m_obj->deref();
    }
    T* operator->() { return m_obj; }
    T& operator*() { return *m_obj; }
};

int main()
{
    // 진짜 포인터처럼 AutoPtr를 사용하면 됩니다. 
    AutoPtr<Car> p1 = new Car;      // AutoPtr<Car> p1(new Car)
    p1->Go();       // p1.operator->()의 원리 입니다. 
    AutoPtr<Car> p2 = p1;


    // webkit에서는 AutoPtr로 참조 계수를 관리한다.
}



