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

int handler(int hwnd, int msg , int a, int b){
    switch(msg)
    {
        case WM_LBuTTONDOWN: std::cout << "LBUTTON" << std::endl; break;
        case WM_KEYDOWN: std::cout << "KEYDOWN" << std::endl; break;
    }
    return 0;
}

int main()
{
    int h1 = ec_make_window(&handler);
    int h2 = ec_make_window(&handler);
    ec_process_message();
}
