/*
*/

#include <iostream>
//using namespace std;

/*
- 
*/

using namespace cppmaster;

// 가상함수의  Table 은 안 써도 파생 클래스마다 생성되므로
// msg : 함수 pointer table을 만들어준다. 
struct MSG_ENTRY
{
    int n;
    void (*handler)();
};

class Window
{
    int hwnd;
    static std::map<it,Window*> this_map;   // hwnd : this 의 map
                                            // static function안에서 this 값을 찾아서 
                                            //  다른 member function을 call 할때 넘겨주기 위해서이다
public:
    void Create()
    {
        hwnd = ec_make_windw(&handler);
        this_map[hwnd] = this;
    }

    // 아래 가상 함수에서 처리할 메시지를 담을 배열을 반환해야 한다. 
    virtual MSG_ENTRY* GetMessageEntry()
    { 
        return nullptr;
    }

    static int handler(int hwnd, int msg , int a, int b){
        Window* self = this_map[hwnd];  // this_map은 static이므로 접근 가능

        if(self == nullptr) return 0;

        // 여기는 가상함수가 아님
        MSG_ENTRY* arr = self->GetMessageEntry();
        if(arr == nullptr) return 0;
        while(arr->handler != nullptr){
            if(arr->n == msg)
            {
                void(Window::*f)() = arr->handler;
                (self->*f)();
            }
            ++arr;
        }
        
        return 0;
    }
};
std::map<int,Window*> Window::this_map;

// -----------------------------

calss MyWindow : public Window
{
public:
    virtual MSG_ENTRY* GetMessageEntry() override
    {
        using HANDLER = void(Window::*)();
        static MSG_ENTRY arr[] = {
            {WM_LBUTTONDOWN, static_cast<HANDLER>(&MyWindow::OnLButton) },
            {WM_KEYDOWN, static_cast<HANDLER>(&MyWindow::foo) },
            {0,0}
        };
        return arr;
    }
    void OnLButtonDown() { std::cout << "MyWindow LButtonDown" << std::endl; }
    void foo() { std::cout << "foo" << std::endl; }
};

int main()
{
    Window w;
    w.Create();     // 이 순간 Window가 생성되어야 한다. 
    /*
    int h1 = ec_make_window(&handler);
    int h2 = ec_make_window(&handler);
    */
    ec_process_message();
}
