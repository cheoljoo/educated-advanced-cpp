#include <iostream>

// C++11 ������ int2type�� ������Ų �Ʒ� ���ø��� �����մϴ�.
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};
// �Ʒ� 3���� ��� �ٸ� Ÿ��
//integral_constant<int, 0> n0;
//integral_constant<int, 1> n1;
//integral_constant<short, 0> s0;

// �Ʒ� 2���� �߿��մϴ�.
// true/false           : ��/������ ��Ÿ���� ��, ���� Ÿ��
// true_type/false_type : ��/������ ��Ÿ���� Ÿ��, �ٸ� Ÿ��
using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// ���� is_pointer�� �Ʒ�ó�� ����� �˴ϴ�.
template<typename T> struct is_pointer     : false_type {}; // value = false
template<typename T> struct is_pointer<T*> : true_type  {}; // value = true


int main()
{

}

