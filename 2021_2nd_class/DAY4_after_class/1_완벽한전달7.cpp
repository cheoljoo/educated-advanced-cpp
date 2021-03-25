#include <iostream>

/*
int n = 10;
int& r = n; 
auto a1 = r; // r�� ���� ���� auto �� �캯�� ������ const �� ������ Ÿ�԰���
			 // �׷��� "int a1 = r"
decltype(auto) a2 = r; // �캯�� Ÿ�԰� ��Ȯ�� ���� Ÿ������ ����
						// int& a2 = r
*/
int& foo(int& a, double b, char c) { a = 100; return a; }

// ���� �Լ��� ��ȯ ���� �Ϻ��ϰ� ��ȯ�ؾ� �մϴ�.

template<typename F, typename ... Ts> 
decltype(auto) chronometry(F f, Ts&& ... args)
{
	return f(std::forward<Ts>(args)...);
}


int main()
{
	int n = 10;

	int& ret = chronometry(foo, n, 3.4, 'A');
	ret = 300; 
	std::cout << n << std::endl; // 300
}



