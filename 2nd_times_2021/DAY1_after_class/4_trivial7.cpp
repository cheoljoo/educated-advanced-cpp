#include <iostream>
#include <type_traits> 

// trivial         : Ư���Լ�(������, ����, ����, �Ҹ���)�� �ϴ� ���� "�ڸ��Ѱ� ?"
// standard layout : �޸� ������ C�� ȣȯ �Ǵ°� ?
// pod : Plain Old Data

// standard layout  ������ trivial �ƴ�.
/*
struct Test	
{
	int x;
	int y;
	Test() {}
};
*/
/*
// trivial ������ SL �ƴ�
struct Test
{
	int x;
private:
	int y;
};
*/
/*
// ��� �ƴ�.
struct Test
{
	int x;
	int y;

	virtual void foo() {}
};
*/
struct Test
{
	int x;
	int y;
	Test() = default;
};
// POD ���� = trivial && standard_layout
int main()
{
	bool b1 = std::is_trivially_default_constructible<Test>::value; // False
	bool b2 = std::is_standard_layout<Test>::value;

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}
