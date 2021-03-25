#include <iostream>
void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
// main					chronometry						hoo(int&&)
// hoo(10)	===============================================> ok
// chronometry(10) =====> int&& arg
//						  hoo(arg) ========================> error. arg�� lvalue
//						  hoo(static_cast<int&&>(arg)   ===> ok. 

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10 ���� 10�� rvalue ������ arg�� lvalue �Դϴ�.
	//f(arg); // ���ڵ�� hoo(int&)�� ã�Ե˴ϴ�.!!

	// �ذ�å : arg�� �ٽ� rvalue�� ��ȯ�ؼ� �Լ� ȣ��
	f( static_cast<int&&>(arg) );
}

int main()
{
	hoo(10); 
	chronometry(hoo, 10); 
}
