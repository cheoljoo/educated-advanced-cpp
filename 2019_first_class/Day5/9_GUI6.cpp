/*
- virtual에서 파생클래스 function call 로 
    template사용하여 CRTP

    C++ nana library
*/

#include <iostream>
//using namespace std;

/*
- 
*/

using namespace cppmaster;


// 핵심 2. this를 자료구조에 보관하는 기술
class Window
{
protected:
    int hwnd;
    static std::map<it,Window*> this_map;   // hwnd : this 의 map
public:

    void OnLButtonDown(){} 
    void OnKeyDown(){} 

    // Factory Method
    // 아래 함수에서 DoCreate()가 Factory Method
    void Create() { DoCreate(); }
    virtual void DoCreate() = 0;
};
// static member data는 이렇게 외부에 선언이 있어야 한다. 
std::map<int,Window*> Window::this_map;


// CRTP로 메세지를 처리하기 위한 파생클래스
template <typename T> class MsgWindow : public Window
{
    virtual void DoCreate() override
    {
        hwnd = ec_make_windw(&handler);
        this_map[hwnd] = this;
    }
    static int handler(int hwnd, int msg , int a, int b){
        T* self = static_cast<T*>(this_map[hwnd]);  // this_map은 static이므로 접근 가능
        switch(msg)
        {
            case WM_LBuTTONDOWN: 
                self->OnLButtonDown(); // 이 함수는 static안에 들어오서 문제다.
                                // 그러나, OnLButtonDown에서는 this가 필요하다. 
                break;
            case WM_KEYDOWN: 
                self->OnKeyDown();  
                break;
        }
        return 0;
    }
};

// -----------------------------

calss MyWindow : public MsgWindow<MyWindow>
{
public:
    void OnLButtonDown()
    { 
        std::cout << "MyWindow LButtonDown" << std::endl;
    }
    void OnKeyDown()
    {
        std::cout << "MyWindow KeyDown" << std::endl;
    }
};


int main()
{
    //Window w;
    //w.Create();     // 이 순간 Window가 생성되어야 한다. 

    Window* p = new MyWindow;
    p->Create();
    ec_process_message();
}
