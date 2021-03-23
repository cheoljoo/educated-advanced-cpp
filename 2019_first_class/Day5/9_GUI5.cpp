/*
- MACRO를 이용하여 바꾼다.
- https://docs.wxwidgets.org/3.0/overview_events.html
- 가상 함수 테이블 때문에 메모리 사용량이 많아져서
- MFC 팀에서 가상함수 안 쓰기 위해서 이렇게 MACRO로 고쳤다.
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

#define DECLEARE_EVENT_MAP() \
    virtual MSG_ENTRY* GetMessageEntry() override;

// 함수 구현을 위한 매크로 (class 외부 구현) 
#define BEGIN_EVENT_MAP(classname) \
    MSG_ENTRY* classname::GetMessageEntry() \ 
    { \ 
        using HANDLER = void(Window::*)(); \ 
        static MSG_ENTRY arr[] = {  

#define ADD_EVENT(message,function) \ 
            {message, static_cast<HANDLER>(function) },

#define  END_EVENT_MAP \
            {0,0}   \
        }; \
        return arr; \
    }

calss MyWindow : public Window
{
public:
    void OnLButtonDown() { std::cout << "MyWindow LButtonDown" << std::endl; }
    void foo() { std::cout << "foo" << std::endl; }

    DECLEARE_EVNET_MAP
};
BEGIN_EVENT_MAP(MyWindow)
    ADD_EVENT(WM_LBUTTONDOWN, &MyWindow::OnLButton)
    ADD_EVENT(WM_KEYDOWN, &MyWindow::foo)
END_EVENT_MAP()

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
