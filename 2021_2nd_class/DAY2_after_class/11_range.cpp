// 11_range
#include <iostream>
#include <vector>
#include <ranges> // C++20 ���

// C++20 ���� RANGE ��� ���ο� ������ STL �� �����մϴ�.
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9 };


	// r �� ���������� v�� ������, ���� �Լ����� �����ϰ� �ִٰ�.!!!
	// ��ȸ �Ҷ� v�� ��� ��ҿ� ���� �Լ� ����
	auto r = v | std::ranges::views::filter([](int a) { return a % 2 == 0; })
			   | std::ranges::views::take(3);

	v[0] = 100;

	// r���� ��Ҹ� ������ ���� ���� - "������ ����"
	for (auto n : r)
		std::cout << n << std::endl;

	// range �� ��� ���� ������ �����ϻ��Դϴ�.
	std::ranges::take_view tv(v, 3); // ���������� v������ �����ϴٰ� 3�������� ������
	std::ranges::filter_view fv(tv, [](int a) { return a % 2 == 0; });
	
	
//	auto r2 = v | std::ranges::views::take(3); // ���ڵ尡 ���� ����

	for (auto n : fv)
		std::cout << n << std::endl;		   

	
}

// ���� ��� �����ҽ��� cafe.naver.com/cppmaster �� �ø��ڽ��ϴ�.



