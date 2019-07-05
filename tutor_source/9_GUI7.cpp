// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;
#include <map>
// 핵심 2. this를 자료구조에 보관하는 기술
class Window
{
protected:
	int hwnd;
	static std::map<int, Window*> this_map;
public:
	void LButtonDown() {}
	void KeyDown() {}
};
std::map<int, Window*> Window::this_map;

// CRTP로 메세지를 처리하기 위한 파생 클래스
template<typename T> class MsgWindow : public Window
{
public:
	void Create()
	{
		hwnd = ec_make_window(&handler);
		this_map[hwnd] = this;
	}
	static int handler(int handle, int msg, int a, int b)
	{
		T* self = static_cast<T*>(this_map[handle]);
		switch (msg)
		{
		case WM_LBUTTONDOWN:	self->LButtonDown();	break;
		case WM_KEYDOWN:		self->KeyDown();		break;
		}
		return 0;
	}
};
//--------------------------------------------
class MyWindow : public MsgWindow<MyWindow>
{
public:
	void LButtonDown() { std::cout << "MyWindow LButtonDown" << std::endl; }
};

int main()
{
	MyWindow w;
	w.Create();
	ec_process_message();
}


