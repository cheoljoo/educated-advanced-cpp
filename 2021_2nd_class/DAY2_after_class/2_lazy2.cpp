// �Ʒ� �ڵ�� ������ �ϸ� ������ ������� ?
template<typename T> void foo(T a)
{
//	if (false)
//		*a = 10;

	// C++17 �� ���ο� if ��
	// ������ �ð� if
	// ������ �ð��� ������ �����ؼ�. ������ �Ǹ�
	// "���ø� ==> C++�ڵ�" �� ������ ����(�ν��Ͻ�ȭ �ȵ�)
	// g++ : -std:c++17
	// vc  : /std:c++latest
	if constexpr (false)
		*a = 10;
}

int main()
{
	foo(10);
}