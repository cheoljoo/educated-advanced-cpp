// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;

int handler(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << std::endl;break;
	case WM_KEYDOWN:  	 std::cout << "KEYDOWN" << std::endl;break;
	}
	return 0;
}
int main()
{
	int h1 = ec_make_window(&handler);
	int h2 = ec_make_window(&handler);
	ec_process_message();
}



