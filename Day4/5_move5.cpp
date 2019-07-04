/*
- 
*/

#include <iostream>
#include <string>
//using namespace std;

/*
- 클래스가 자원을 할당하지 않으면 - 소멸자가 없어도 된다. 
- 클래스가 자원을 할당하면 3가지가 필요하다. rule of 3 (C++98)
    - 소멸자
    - 복사생성자
    - 대입연산자
- C++11 추가로 2개 더 필요 (move) - rule of 5
    - move 생성자
    - move 대입연산자

- move 계열 함수를 제공하지 않으면
    - 복사계열 함수가 호출된다.   &&이 없으면  const &이 다 받아준다.
*/

class Test
{
    int data;
    int* resource;
public:
    Test() {}   // resource = new int;
    ~Test() {}
    Test(const Test& t){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(const Test& t){std::cout << __PRETTY_FUNCTION__ << std::endl;  return *this; }

    Test(Test&& t){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(Test&& t){std::cout << __PRETTY_FUNCTION__ << std::endl;  return *this; }
};


int main()
{
    Test t1;
    Test t2 = t1;
    t2 = t1;

    Test t3 = std::move(t1);    // static_cast<Test&&>(t1)
    t3 = std::move(t1);
}
