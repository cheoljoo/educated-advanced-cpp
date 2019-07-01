#include <iostream>
#include <vector>
#include <atomic> // C++11 멀티스레드에 안전한 타입

templae<typename T> 
class RefCountedBase
{
    mutable std::atomic<int> m_refCount = 0;
public:
    void ref() const
    {
        m_refCount.fetch_add(1);
    }
    void deref() const
    {
        // 일반 멤버 함수에서 this : RefCountedBase* this
        // 상수 멤버 함수에서 this : const RefCountedBase* this
        m_refCount.fetch_sub(1);
            // fetch가 CPU lock을 쓰므로 성능적으로 더 유리하다. 
            // mutex lock은 보통 system lock을 사용하게 된다.
        int cnt = m_refCount.load();
        if(cnt == 0){
            delete static_cast<const T*>(this); // ok : 이 모양도 가능하다. this가 const이니 맞춰준다. const T*도 delete가 된다.
        }
    }
    // 구글 " android github"
    // https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/LightRefBase.h
protected:
    ~RefCountedBase() {}
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


