/*
- 
*/

#include <iostream>
#include <functional>
//using namespace std;
using namespace std::placeholders;

/*
- 
*/

class Button
{
public:
    //void (*handler)(); // 여기는 인자가 없는 함수만 받을수 있다.
    std::function<void()> handler;  // 선언은 인자 없게 했지만, bind 만 있으면 인자 늘릴수 있다. 
    void Click() { handler(); }
};

void foo() { std::cout << "foo" << std::endl; }
void goo() { std::cout << "goo" << std::endl; }
void hoo(int id) { std::cout << "hoo : " << id << std::endl; }


int main()
{
    Button b1,b2;
    //b1.handler = &foo;
    //b2.handler = &goo;
    
    // nana open source C++ GUI 라이브러리 (2017 : C++17) 
    /*
    From rm ;
    b1.handler = [&rm](){ rm.Close()};  // [&rm]은  {}안에서 rm을 쓸수 있게 해달라.
    */

    b1.handler = []() { std::cout << "Dialog Close" << std::endl; };
    //b1.handler = &foo;
    //b1.handler = std::bind(&hoo,1);
    b2.handler = std::bind(&hoo,2);
    b1.Click();
    b2.Click();
}


