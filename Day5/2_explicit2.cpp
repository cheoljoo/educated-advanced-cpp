/*
- 
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
//using namespace std;

/*
- explicit는 생성자 앞에 붙여주는게 좋다. 
- 그래야 int -> Vector로 바꿔주는 등의 일을 알아서 하지 못한다.  (2_explicit.cpp)
*/


void foo(std::string s){}

int main()
{
    // string의 생성자는 explicit가 아니다.
    std::string s1("hello");    // explicit이면 이것이 error
    std::string s2 = "hello";   //  복사 초기화 // ok
    // foo("hello"); // explicit생성자라면 error

    // vector는 생성자가 explitit
    std::vector<int> v1(10);    // 초기값이 아닌 크기. 10개짜리 vector
    std::vector<int> v2 = 10; // error
    std::vector<int> v3 {10 }; // 1개짜리 vector인데 초기값이 10
    std::vector<int> v4 = { 10} ;  // ok
 
    // c++ 표준 스마트 포인터는 모두 explicit
    std::unique_ptr<int> p1(new int);
    std::unique_ptr<int> p2 = new int;  // error
}
