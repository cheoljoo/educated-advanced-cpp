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

// 객체를 참조 계수 기반으로 관리하기로 결정했다면
// raw pointer를 사용하게 하지 말자!!
// 스마트 포인터를 도입해야 한다.
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
    // 진짜 포인터처럼 -> 를 사용할수 있어야 한다.
    T* operator->() { return m_obj; }
    T& operator*() { return *m_obj; }
};

int main()
{
    //Car* p1 = new Car; p1->ref();
    AutoPtr<Car> p1 = new Car;      // AutoPtr<Car> p1(new Car)

    //Car* p2 = p1;   p2->ref();
    AutoPtr<Car> p2 = p1;

    //p2->deref();
    //p1->deref();
}



