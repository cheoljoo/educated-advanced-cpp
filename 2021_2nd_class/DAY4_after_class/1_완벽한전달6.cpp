#include <iostream>
void foo(int a, double b, char c) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

// �ٽ�. �Ϻ��� ������ �Ϸ���
// 1. ���ڸ� ������ "T&&" �� ���
// 2. ���ڸ� �ٸ����� �������� "std::forward<T>(arg)"�� ��� ����
// 3. "�������� ���ø�"�� ����ؾ� �Ѵ�. - C++11

// ����: �Ʒ�ó�� �����
// Ts : Ÿ�� �ϳ��� �ƴ϶� ������ Ÿ���� ���� "���ø� �Ķ���� ��"
//		int, double, char
// args : 10, 3.4, 'A'  �� �ֽ��ϴ�. "�Լ� �Ķ���� ��" �̶�� �մϴ�.
template<typename F, typename ... Ts> void chronometry(F f, Ts&& ... args)
{	
	f( std::forward<Ts>(args)... ); 
	// ... : ���� Ǯ�� �޶�
	// f( std::forward<int>(10), std::forward<double>(3.4), std::forward<char>('A' ) )
}

int main()
{
	int n = 10;

	chronometry(foo, 10, 3.4, 'A'); 
	chronometry(goo, n);  

	std::cout << n << std::endl;
}



