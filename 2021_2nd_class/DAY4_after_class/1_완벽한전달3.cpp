#include <iostream>
void foo(int a) {}
void goo(int& a) { a = 100; }

// ���ڵ�� �Ѱ����� �������� �ֽ��ϴ�. �Ʒ� hoo�� ������ ������
void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok
	chronometry(hoo, 10); // error  <<==== ���⼭ ������ ���� ���� ����
						// ���ΰ� �ذ�å�� �����ҽ�����..


	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n);

	std::cout << n << std::endl;
}
