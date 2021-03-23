// 3_참조계수8.cpp
//
#include <stdio.h>
#include <iostream>
#include <vector>

// 237 page. thin template
// 클래스 템플릿이 너무 많은 타입에 대해서 인스턴스화 될때 코드가 커닐수 있다. - code bloat
// code bloat를 막기 위한 기술

// T를 사용하지 않는 멤버 함수를 템플릿이 아닌 기반 클래스를 만들어서 상속받자.!!

// 클래스 템플릿을 만들때
// 템플릿 파라미터 T를 사용하지 않는 멤버 함수는  (여기서는 이게 많을수 있기에 code memory절약을 위해서)
// 템플릿이 아닌 기반 클래스를 만들어서 상속 받자


class RefCountedBase
{
protected:
        mutable int m_refCount = 0 ;
public:
        // 상수 객체라도 수명을 관리할수 있어야 한다.
        // 참조 계수를 조작하는 함수는 반드시 "상수 멤버함수"이어야 한다.
		void ref() const { ++m_refCount; }
};


#define WTF_MAKE_NONCOPYABLE(classname) \
    classname(const classname&) = delete; \
    classname& operator=(const classname&) = delete;
template <typename T>
class RefCounted : public RefCountedBase
{
    // 이 클래스는 (또는 기반 클래스)는 복사 되면 안된다. 
    // 컴파일러가 복사 생성자를 만들지 못하게 된다. 
    // 아래 2개는 항상 쌍으로 다닌다.  그래서 macro를 이용한다. 
    //RefCounted(const RefCounted&) = delete; // c++11 함수 삭제
    //RefCounted& operator=(const RefCounted&) = delete;  // 대입도 삭제
    WTF_MAKE_NONCOPYABLE(RefCounted);
public:
    void deref() const      // void deref( RefCounted* this)
    {
        // 일반 멤버 함수에서 this : RefCounted* this
        // 상수 멤버 함수에서 this : const RefCounted* this
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
};

class Truck : public RefCounted<Truck>
{
    public:
        Truck(){}
        ~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
    Car* p1 = new Car; p1->ref();
    Car* p2 = p1;   p2->ref();

    //Car* p3 = new Car(*p1);         // 참조계수까지 복사가 된다.  참조계수는 복사되지 않게 해야 한다. 
    p2->deref();
    p1->deref();
}



