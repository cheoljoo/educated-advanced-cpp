// 4�� �ҽ�-> 3���� �����ϼ���
#include <iostream>

// �ȵ巹�� �˷��������ť - "���̽���"
template<int N> struct int2type
{
	enum { value = N };
};

int main()
{
	foo(0);
	foo(1); // 0, 1 ��� ���� Ÿ��(int)
			// foo(0), foo(1) �� ���� �Լ� ȣ��

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0, t1�� ��� �ٸ� Ÿ���̴�.
			 // foo(t0), foo(t1) �� �ٸ� �Լ� ȣ��

			// 77, 78 �� ���� Ÿ��(int)
			// int2type<77>, int2type<78> �� �ٸ� Ÿ��
}
