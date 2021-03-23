// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // ī��(cafe.naver.com/cppmaster)�� �ֽ��ϴ�.
using namespace cppmaster;
#include <map>
// �ٽ� 2. this�� �ڷᱸ���� �����ϴ� ���
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

// CRTP�� �޼����� ó���ϱ� ���� �Ļ� Ŭ����
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


