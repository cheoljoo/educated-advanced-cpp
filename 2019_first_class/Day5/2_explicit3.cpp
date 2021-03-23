/*
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

void foo(std::initializer_list<int> e)
{
}
int main()
{
    // initializer_list : 메모리에 연속적으로 놓은 동일 타입이 객체를 관리하는 도구
    //          stack에 연속적으로 놓여직 됨. VC++는 시작과 끝 주소만을 가짐
    std::initializer_list<int> s = {1,2,3,4,5,6,7};

    foo(s);
    foo({1,2,3,4,5,6,7});  // ok : 이게 가능하다.  이것때문에 initializer_list를 만듦

    auto p = s.begin();
    std::cout << *p << std::endl;
}
