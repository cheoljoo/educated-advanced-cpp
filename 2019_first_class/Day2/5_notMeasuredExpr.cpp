/* 5_평가되지 않는 표현식
- 
*/

#include <iostream>
//using namespace std;

/*
- c++에서 평가되지 않는 표현식은 4개가 있다. (unevaluated expression)
    - sizeof(foo(0);    // 반환값의 크기
    - decltype(foo(0)); // 반환값의 타입
    - noexcept(foo(0);  // 함수가 예외가 있는지 조사
    - typeid(foo(0));   // 반환값의 타입 정보
*/

short foo(int n)
{
    std::cout << "foo" << std::endl;
    return 0;
}

int main()
{
    int n=0;
    std::cout << sizeof(n)      << std::endl;   // 4 => 4
    std::cout << sizeof(&foo)      << std::endl;    // 4 => 8 
    //std::cout << sizeof(foo)      << std::endl; // error
    
    // sizeof안의 foo(0)은 호출되지 않는다.  ==> 평가되지 않는 표현식 
    std::cout << sizeof(foo(0))      << std::endl;  // 2  : return 값의 크기
}
