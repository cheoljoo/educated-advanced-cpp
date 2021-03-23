#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class People
{
	std::string name;
	int age;
public:
	People(std::string name, int age) : name(name), age(age) {}

	// C++98 ���Ϸ��� : <, >, ==, !=, <=, >= �� �����ؾ� �մϴ�.
	// C++20 space operator �Ѱ��� �����ϸ� �˴ϴ�.
	auto operator<=>(const People&) const = default;
};

int main()
{
//	bool b1 = 10 < 20;  // ===> ( 10 <=> 20)  < 0  �� ����!

//	bool b2 = 10 <=> 20; // C++20 �� three way comparison		
						// A <=> B    A �� ũ�� ��� �� 0�̻�
						//            B �� ũ�� ��� �� 0����
						//            ������ 0

	People p1("kim", 20);
	People p2("lee", 10);
	People p3("lee", 50);

	std::cout << (p1 < p2) << std::endl;
	std::cout << (p2 < p3) << std::endl;

	std::vector<People> v;
	v.emplace_back("kim", 20);
	v.emplace_back("kim", 10);
	v.emplace_back("kim", 24);

	std::sort(v.begin(), v.end());
}