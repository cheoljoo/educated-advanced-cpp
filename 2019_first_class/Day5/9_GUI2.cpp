/*
- windows용 코드
    - http://cafe.naver.com/cppmaster
*/

#include <iostream>
//using namespace std;

/*
- 
*/

using namespace cppmaster;


class Window
{
    int hwnd;
public:
    void Create()
    {
        hwnd = ec_make_windw(&handler);
    }

    // 핵심 1. 아래 함수는 반드시 static 멤버 함수가 되어야 한다. 
    // 그래야 위에서 pointer로 잡아 쓸수 있다. 
    // 인자로 첫번째에 *this이 오지 않게 하기 위해서 static을 붙인다. 
    // 인자는 4개를 원한다. 
    static int handler(int hwnd, int msg , int a, int b){
        switch(msg)
        {
            case WM_LBuTTONDOWN: std::cout << "LBUTTON" << std::endl; break;
            case WM_KEYDOWN: std::cout << "KEYDOWN" << std::endl; break;
        }
        return 0;
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
