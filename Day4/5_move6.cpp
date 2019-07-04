/*
- 
*/

#include <iostream>
#include <string>
//using namespace std;

/*
-
*/

class Test
{
    int data;
    std::string s = "hello";
public:
    Test() {}   // resource = new int;
    ~Test() {}
    Test(const Test& t):data(t.data),s(t.s){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(const Test& t)
    {
        data = t.data;
        s = t.s;
        std::cout << __PRETTY_FUNCTION__ << std::endl;  return *this; 
    }

    // move생성자에서는 모든 멤버를 반드시 move로 옮기자
    Test(Test&& t):data(t.data),s(std::move(t.s)){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(Test&& t)
    {
        data = std::move(t.data);
        s = std::move(t.s);
        std::cout << __PRETTY_FUNCTION__ << std::endl;  return *this; 
    }
};


int main()
{
    Test t1;
    Test t2 = t1;
    t2 = t1;

    Test t3 = std::move(t1);    // static_cast<Test&&>(t1)
    t3 = std::move(t1);
}
