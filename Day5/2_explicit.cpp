/* 2_explicit
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

class Vector
{
public:
    // explicit 생성자 : 복사 초기화를 사용할 수 없다. 
    // 직접 코기화가 가능한다. 
    explicit Vector(int sz){}
};

void foo(Vector v){} // Vector v = 10

int main()
{
    Vector v1(10);      // direct initialization : default 생성자
    Vector v2 = 10;     // copy initialization : 복사 생성자
    Vector v3{10};      //  direct

    foo(v1);    // ok
    foo(10);    // 복사 초기화가 일어나는 것으로 안되게 하는게 좋다.
                // 생성자 만들때 explicit 사용
                // error : explicit붙일때
}
