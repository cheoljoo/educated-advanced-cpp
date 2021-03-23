/*
- windows용 코드
    - http://cafe.naver.com/cppmaster
- this_map이라는 자료 구조 도입
- 90년대 유행한 기술임

- 파생 클래스가 가상함수를 2개만 해도 가상함수 table은 모두 잡힌다.
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

    // 핵심 1. 아래 함수는 반드시 static 멤버 함수가 되어야 한다. 
    // 그래야 위에서 pointer로 잡아 쓸수 있다. 
    // 인자로 첫번째에 *this이 오지 않게 하기 위해서 static을 붙인다. 
    // 인자는 4개를 원한다. 
    static int handler(int hwnd, int msg , int a, int b){
        // 현재 윈도우 번호를 가지고 this를 얻어온다.
        Window* self = this_map[hwnd];  // this_map은 static이므로 접근 가능
        // self만 있으면 모든 member 접근 가능
        
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
    virtual void OnLButtonDown(){} = 0;
    virtual void OnKeyDown(){} = 0;
};
// static member data는 이렇게 외부에 선언이 있어야 한다. 
std::map<int,Window*> Window::this_map;

// -----------------------------

calss MyWindow : public Window
{
public:
    virtual void OnLButtonDown() override
    { 
        std::cout << "MyWindow LButtonDown" << std::endl;
    }
    virtual void OnKeyDown() override
    {
        std::cout << "MyWindow KeyDown" << std::endl;
    }
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
