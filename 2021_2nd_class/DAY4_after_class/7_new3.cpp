#include "cppmaster.h"
#include <vector>

// DBConnect �� �����ڿ��� DB�� �����Ѵٰ� ������ ������
class DBConnect {};

int main()
{
	std::vector<DBConnect> v(5);

	v.resize(3); // �̼��� �پ�� 2���� ���� �޸𸮴� ��� ����������
				 // 2���� ��ü�� �Ҹ��ڴ� ȣ��Ǿ�� �մϴ�.
				 // �Ҹ����� ����� ȣ���� �ʿ� �մϴ�.

	v.resize(4); // �þ �߰��� �޸𸮴� �̹� ���� �մϴ�.
				 // ������, �����ڸ� ��������� ȣ�⿡��
				 // DB�� �����ؾ� �մϴ�
				 // �������� ����� ȣ���� �ʿ� �մϴ�.
}






/*
int main()
{
	std::vector<int> v(10, 3);

	v.resize(7);  // �� ������ ������ ������ ���ô�.

	std::cout << v.size()     << std::endl; // 7
	std::cout << v.capacity() << std::endl; // 10

	v.push_back(0); // ���� �Ѱ� �߰�

	std::cout << v.size()     << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10

	v.shrink_to_fit(); // ������ �޸� ����

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 8


	v.push_back(0); // ���� �Ѱ� �߰� - VC : 12

	std::cout << v.size() << std::endl; // 9
	std::cout << v.capacity() << std::endl; // 12

//	st = [1, 2, 3, 4];
//	st.append(10) // ���������� �󸶳� �ø���� ? 8
}
*/




