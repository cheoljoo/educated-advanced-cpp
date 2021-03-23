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

	// C++98 비교하려면 : <, >, ==, !=, <=, >= 를 제공해야 합니다.
	// C++20 space operator 한개만 제공하면 됩니다.
	auto operator<=>(const People&) const = default;
};

int main()
{
//	bool b1 = 10 < 20;  // ===> ( 10 <=> 20)  < 0  로 변경!

//	bool b2 = 10 <=> 20; // C++20 의 three way comparison		
						// A <=> B    A 가 크면 결과 는 0이상
						//            B 가 크면 결과 는 0이하
						//            같으면 0

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