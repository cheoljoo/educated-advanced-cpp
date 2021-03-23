/* 10_trivial1
- trivial : 생성자 , 복사 생성자 , 소멸자 , 대입연산자 등이 하는 일이 없을 경우 'trivial하다' 라고 한다.
*/

#include <iostream>
//using namespace std;

/*
- trivial하려면
    - 1. 가상함수가 없고
    - 2. 객체형 멤버가 없거나 멤버의 생성자가 trivial하고
    - 3. 기반 클래스가 없거나 기반클래스의 생성자가 trivial하고
    - 4. 사용자가 만든 생성자가 없을때
*/

class A {};

class B : public A
{
    //  A a;
public:
    // virtual void foo() { std::cout << "foo" << std::endl; }
    //  virtual table을 초기화하는 일을 하므로 trivial하지 않다.
};

int main()
{
    // B는 생성자가 trivial할까요?
    // B의 생성자가 trivial하면 생성자 호출을 하지 않아도 사용가능해야 합니다. 
    B* p = static_csst<B*>(operator new(sizeof(B)));
    p->foo();

}
