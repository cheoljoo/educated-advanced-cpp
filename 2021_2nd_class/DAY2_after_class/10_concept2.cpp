// 10_concept2
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <concepts> // �� �ȿ� concept1 ���� ���� "Addable" ���� ǥ�� concept�� �ֽ��ϴ�.

template<typename IT, typename T> requires (! std::predicate<T, std::iter_value_t<IT> > )
void find(IT first, IT last, T value)
{
	std::cout << "�� ����" << std::endl;
}

// predicate<F, Ÿ��> : F��� �Լ� Ÿ���� "Ÿ��"�� ���ڷ� ������ �ִ°� ?
// iter_value_t<�ݺ���> : �ݺ��ڰ� ����Ű�� ����� Ÿ��..
//						IT::value_type => C++98 ǥ��

template<typename IT, typename T> requires std::predicate<T, std::iter_value_t<IT> >
void find(IT first, IT last, T func) 
{
	std::cout << "�Լ� ���� ����" << std::endl;
}

bool foo(int) { return true; }

int main()
{
	// STL �� ����
	//std::find(first, last, 30); // �� (30) ã��
	//std::find_if(first, last, foo); // ���� �˻�(foo �Լ��� ���ʴ�� ��� ����)

	// STL�� �̷�
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	find(x, x+10, 30); // �� (30) ã��
	find(x, x + 10, foo); // ���� �˻�(foo �Լ��� ���ʴ�� ��� ����)

}

