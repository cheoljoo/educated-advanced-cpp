/* 1_checked_delete  37 page
- 
*/

#include <iostream>
//using namespace std;

/*
-  foo가 Test 보다 위에 있으면 Test를 써야 하므로 전방 선언 필요
- 클래스 전방선언
    -  완전한 선언이 없어도 포인터 변수는 만들수 있다. 
    -  불완전한 타입 (incomplete type) : 소멸자가 불리지 않는다. 
- 불완전한 type을 사용할때는 그냥 delete하면 안된다.
    - 그래서 check하고 delete하자
*/

class Test;  // 클래스 전방선언
            // 완전한 선언이 없어도 포인터 변수는 만들수 있다. 
            // 불완전한 타입 (incomplete type) : 소멸자가 불리지 않는다. 

void foo(Test* p)
{
    //sizeof(Test);   // complete 타입만 크기를 구할수 있다.
                    // compile error를 주어 문제를 잡게 해준다. 

    // 안드로이드 소스의 예전 버전에서 볼수 있던 코드
    // enum{ type_must_be_complete = sizeof(Test) };  // 최적화로 없애지 못하게
    
    // C++ 11 이후에는 static assert를 사용 : compile time
    static_assert( sizeof(Test) > 0 , "error, delete incomplete type");

    delete p;
}

class Test
{
public:
    Test() { std::cout << __PRETTY_FUNCTION__  <<  std::endl; }
    ~Test() { std::cout << __PRETTY_FUNCTION__  <<  std::endl; }
};


int main()
{

    // std::default_delete<int> df;
    // default_delete 소스를 보면 const noexcept를 불이고 (붙일수 있으면 좋다) , 
    // 그 안에 static_assert가 있다.

    Test* p = new Test;
    foo(p);
}
