// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // ī��(cafe.naver.com/cppmaster)�� �ֽ��ϴ�.
using namespace cppmaster;
#include <map>

class Window
{
	int hwnd;
	static std::map<int, Window*> this_map;

public:
	void Create()
	{
		hwnd = ec_make_window(&handler);

		// ������ ��ȣ�� Ű������ this ����
		this_map[hwnd] = this;
	}

	static int handler(int handle, int msg, int a, int b)
	{
		// ���� ������ ��ȣ�� ������ this�� ���´�.
		Window* self = this_map[handle];

		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			self->LButtonDown();   // this->LButtonDown()
			break;
		case WM_KEYDOWN:  	 
			self->KeyDown(); 
			break;
		}
		return 0;
	}
	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};
std::map<int, Window*> Window::this_map;
//--------------------------------------------
class MyWindow : public Window
{
public:
	virtual void LButtonDown() override
	{
		std::cout << "MyWindow LButtonDown" << std::endl;
	}
};
int main()
{
	MyWindow w;
	w.Create();    
	ec_process_message();
}


