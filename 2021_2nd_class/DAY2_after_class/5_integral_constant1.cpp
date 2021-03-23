// integral_constant1.cpp
// traits7�� �����ؿ�����. - �ּ� ����
#include <iostream>
#include <type_traits>

// �����Ϳ� �����Ͱ� �ƴ� ��츦 ������ �Լ� ���ø����� �и�
template<typename T> void pointer(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void not_pointer(const T& v)
{
	std::cout << v << std::endl;
}

template<typename T> void printv(const T& v)
{
	// �Ʒ� �ڵ�� if( false ) �� pointer ���ø��� ���� �Լ��� �ν��Ͻ�ȭ �ϰ� �˴ϴ�.
	if (std::is_pointer_v<T>)
		pointer(v);
	else
		not_pointer(v);		
}
int main()
{
	int n = 10;
	printv(n); 
}

