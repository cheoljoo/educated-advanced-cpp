#include <iostream>

class Point { int x, y; };

//void foo(Point pt) {}      // call by value : ���纻�� �������
//void foo(const Point& pt) {} // lvalue �� rvalue�� ��� ������ �ִ�.

void foo(Point& pt) 
{
	std::cout << "lvalue, ���ڷ� ���� ��ü�� ȣ��ڿ��� ��� ��� �ִ�" << std::endl;
}
void foo(Point&& pt)
{
	std::cout << "rvalue, ���ڷ� ���� ��ü�� ȣ��ڿ��� �ı��ȴ�." << std::endl;
}
int main()
{
	Point pt;
	foo(pt);
	foo(Point());
	
	Point&& r = Point(); // r�� lvalue �Դϴ�. �̸��� �����Ƿ�
	foo(r);	
	///..... ���� ���������� foo �� �����ϸ�, ���̻��� r�� �ʿ� ����.
	foo(static_cast<Point&&>(r)); // �̼��� �޸𸮻��� ��ȭ�� �����ϴ�.
								// ����, r�� foo(rvalue) �������� �����޶�� ��û�ϻ�

	int&& r2 = 10;
	foo(static_cast<int&&>(r2)); // �޸� ��ȭ ����.
	foo(std::move(r2)); // ���� ����!!!
	foo(static_cast<int>(r2));   // ok.. 
	int n = r2;
}
/*
void a(int&& a) {} 
a(5); // ok. rvalue
int b = �Է�;
a(b); // error. b�� lvalue
a(static_cast<int&&>(b)) // ok .. �ּ��� �ڵ�
a(std::move(b)) // ok �� �� �Ϻ��� ����.
*/