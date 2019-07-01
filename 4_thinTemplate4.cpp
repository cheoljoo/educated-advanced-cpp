//  4_thinTemplate4 - 237 page
#include <iostream>


// android 소스에서 
// platform_system_core/libutils/include/Vector.h 열어보세요.  VectorImpl
//   android에서는 Vector같은 것들 표준에 있는 것을 std를 사용하도록 권장한다.

// shared_ptr<int> sp(new int) : ok
//   참조계수를 스마트 포인터가 관리
//   make_shared를 이용해서 객체과 참조계수 객체를 같이 붙여서 memory fragmentation을 방지 할수 있다. 
//   overhead는 2배의 overhaed
// AutoPtr<int> sp(new int): error
// AutoPtr<int> sp(new Car): ok
//  참조 계수를 객체가 관리한다. 


// 실제로는 T 를 쓰는 것들의 크기가 크다.
// 이번에는 T도 VectorBase로 올려본다.
// void* 기반 컨테이너 and template에서는 casting만 책임진다.
class VectorBase
{
protected:
    int size;
    void** buff;
public:
    VectorBase(int sz):size(sz)
    {
        buff = new void*[size];
    }
    ~VectorBase()
    {
        delete[] buff;
    }
    void* front() { return buff[0]; }
    void* last() { return buff[size-1]; }
    int getSize() const { return size; }
};

// template에서는 casting만을 하고 ( compile time)
// 이것은 code memory가 확 줄어든다.
template<typename T>
class Vector : public VectorBase
{
    T* buff;
public:
    Vector(int sz):VectorBase(sz) { }

    T& front() { return static_cast<T&>(buff[0]); }
    T& last(){ return static_cast<T&>(buff[size-1]); }
};

int main()
{
    Vector<int> v1(10);
    Vector<double> v2(10);
}
