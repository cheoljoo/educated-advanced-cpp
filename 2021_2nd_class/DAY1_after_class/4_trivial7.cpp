#include <iostream>
#include <type_traits> 

// trivial         : 특별함수(생성자, 복사, 대입, 소멸자)가 하는 일이 "자명한가 ?"
// standard layout : 메모리 구조가 C와 호환 되는가 ?
// pod : Plain Old Data

// standard layout  이지만 trivial 아님.
/*
struct Test	
{
	int x;
	int y;
	Test() {}
};
*/
/*
// trivial 하지만 SL 아님
struct Test
{
	int x;
private:
	int y;
};
*/
/*
// 모두 아님.
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
// POD 정의 = trivial && standard_layout
int main()
{
	bool b1 = std::is_trivially_default_constructible<Test>::value; // False
	bool b2 = std::is_standard_layout<Test>::value;

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}
