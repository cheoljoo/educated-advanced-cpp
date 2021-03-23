#include <iostream>
#include <type_traits> 

class Test
{
	int x = { 0 }; // �Ʒ��� ����
	int y = 0; // �����ڸ� ����� �ʱ�ȭ ����Ʈ�� �߰�
			   // Test() : x{0}, y(0) {} �� �ڵ��Դϴ�.
public:
//	Test() {} // ����ڰ� ���� ������ - �����Ϸ��� �ϴ����� �ִٰ� ���� 
			  // trivial ������ �ƴ�.
//	Test() = default; // �����Ϸ����� ����Ʈ �����ڸ� ����� �޶�� ��û
					  // C++11
					  // trivial ������
};

int main()
{
	bool b = std::is_trivially_default_constructible<Test>::value; 

	std::cout << b << std::endl;
}
