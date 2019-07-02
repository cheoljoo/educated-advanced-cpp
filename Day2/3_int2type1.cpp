/* 3_int2type1.cpp   115 page
- 
*/

#include <iostream>
//using namespace std;

/*
- 템플릿 : 클래스를 만드는 툴
    - 사용하지 않으면 클래스가 생성되지 않는다. 
    - template은 사용한 코드만 만들어진다.
    - lazy instantiation : 사용된 템플릿만 인스턴스화 (실제 C++ code 생성) 된다. 
*/

template<typename T>
class A
{
    T data;
public:
    void foo(T a)
    {
        *a = 10;    // 1. 템플릿만 있을때는 코드가 안 만들어지므로 error가 나지 않는다.
    }

};

int main()
{
    A<int> a;       // 2. T는 지정은 했지만, foo를 호출하지 않았기 때문에 위의 1번 error가 발생하지 않는다. 
    a.foo(0);       // 3. foo를 사용하므로 error가 발생한다. 
}
