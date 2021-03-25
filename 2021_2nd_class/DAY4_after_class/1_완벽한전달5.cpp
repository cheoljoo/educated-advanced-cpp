#include <iostream>
void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f( static_cast<int&>(arg) ); // �ʿ� ���� ĳ���� ������ �־ �˴ϴ�.
								 // �ᱹ, �����Ͻ� ���ŵ˴ϴ�.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// T&& �� ����ϸ� int&, int&& �� �Լ��� �ڵ������Ҽ� �ִ�.
// �ᱹ �Ʒ� ���ø��� ���� 2���� �Լ��� �����ϰ� �˴ϴ�.
template<typename F, typename T> void chronometry(F f, T&& arg)
{
	// (���ڷ�) lvalue ��(������) lvalue�� ĳ�����ϰ�
	// (���ڷ�) rvalue ��(������) rvalue�� ĳ�����ϰ�
	// f(static_cast<T&&>(arg));

	f( std::forward<T>(arg) ); // std::forward �Լ��� �ᱹ ���� ���� ĳ������ �����մϴ�.

//	std::move(arg); // arg�� ������ rvalue�� ĳ����
		
//	std::forward : static_cast<T&&>(arg);
//	std::move    : static_cast<remove_reference_t<T>&&>(arg); 
}


int main()
{
	int n = 10;

	chronometry(foo, 10); // T=int   ===> static_cast<int&&>(arg) �̹Ƿ� rvalue�� ĳ����
	chronometry(goo, n);  // T=int&  ===> static_cast<int&>(arg)  �̹Ƿ� lvalue�� ĳ����

	std::cout << n << std::endl;
}



