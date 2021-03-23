#include <iostream>


// int a    => �����̸� : a   a�� Ÿ�� : int
// int x[3] => �����̸� : x   x�� Ÿ�� : int[3]
//										 T[N] : ũ�⸦ �˼� �ִ� �迭
//										 T[]  : array of unknown bound
//												(C ��� flexible array ���� ���)

template<typename T> struct is_array
{
	static constexpr bool value = false;
	static constexpr int size = -1;
};
template<typename T> struct is_array<T[]>
{
	static constexpr bool value = true;
	static constexpr int size = -1;
};
template<typename T, int N> struct is_array<T[N]>
{
	static constexpr bool value = true;
	static constexpr int size = N;
};

template<typename T> void foo(const T& a)
{
	// T : int[3]
	if (is_array<T>::value)
		std::cout << "�迭, ũ��� " << is_array<T>::size << std::endl;
	else
		std::cout << "�迭 �ƴ�" << std::endl;
}
struct PACKET
{
	int cmd;
	int data[]; // ok.. flexible array ��� ���. ����ü ������ ����� ������ �ֽ��ϴ�.
};

int main()
{
	// int x[]; // error, ũ�⸦ �˼� ���� �迭�� ���⼭�� ����� �����ϴ�.
	// int x[] = {1,2,3}; // ok.. ��, int x[3] �� �˴ϴ�

	PACKET * p = (PACKET*)malloc(sizeof(PACKET) + sizeof(int) * 20);

	foo(p->data); // data �� ũ�⸦ �˼� ���� �迭 Ÿ�� �Դϴ�.

	free(p)
}





