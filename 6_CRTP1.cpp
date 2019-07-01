//  6_CRTP1  - 195 page

// virtual로 call 하면 MyWindow::Click를 부를수 있다. 
// 그러나, 너무 느려지므로 virtual은 쓰지 않는 것으로 한다.
//
#include <iostream>
//using namespace std;

// android
// libutils/include/utils/singleton.h  : CRTP를 사용하는 singleton    but , 여기서도 다른 방식 추천


// MS오픈소스인 WTL(Window Template Library) 라이브러리가 이벤트를 처리하는 방식
template <typename T>
class Window
{
public:
    void msgLoop()  // msgLoop(Window* this)
    {
        //Click();    // this->Click()
        static_cast<T*>(this)->Click();
    }
    void Click() {
        std::cout << "Window::Click" << std::endl;  // 1
    }
};
class MyWindow : public Window<MyWindow>
{
public:
    void Click(){ std::cout << "MyWindow::Click" << std::endl; }  // 2
};


int main()
{
    MyWindow w;
    w.msgLoop();    // 1을 call

}
