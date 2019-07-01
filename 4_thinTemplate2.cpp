//  4_thinTemplate2 - 237 page
#include <iostream>

// 2개의 타입에 대해 vector사용 => 총 10개의 member함수가 생성됨.
template<typename T>
class Vector
{
    T* buff;
    int size;
public:
    Vector(int sz):size(sz) { buff = new T[size]; }
    ~Vector() { delete[] buff; }

    int getSize() const { return size; }
    T& front() { return buff[0]; }
    T& last(){ return buff[size-1]; }
};

int main()
{
    Vector<int> v1(10);
    Vector<double> v2(10);
}
