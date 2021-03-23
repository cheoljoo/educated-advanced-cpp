#include <iostream>

/*
template<typename T>
void foo(T a)  // void foo(int a)
{
	typename T::type n; // ���� �ϱ�� ? SFINAE �� ����ɱ�� ? ����
	// int::type n
	std::cout << "T" << std::endl; 
}
*/
// SFINAE �� �Լ� ������ ���忡���� ������� �ʽ��ϴ�.
// 1. �Լ��� ���� Ÿ��
// 2. �Լ��� ���� Ÿ��
// 3. �Լ��� ���ø� ���� 
// ������ ����˴ϴ�.

// 1. ���� Ÿ�Կ� ����
// template<typename T>
// typename T::type foo(T a) { return 0; }

// 2. �Լ� ���� Ÿ��
//template<typename T>
//int foo(T a, typename T::type n = 0) { return 0; }

// 3. ���ø� ���ڿ� ����
template<typename T,
		 typename T2 = typename T::type> 
int foo(T a) { return 0; }


void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	foo(3);
}
