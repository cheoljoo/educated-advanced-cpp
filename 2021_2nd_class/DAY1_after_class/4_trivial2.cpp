#include <iostream>
#include <type_traits> // C++11. 타입의 특성을 조사하는 도구.

// trivial 여부 조사하기


class Test
{
public:
	//virtual void foo() {}
};
int main()
{
	// 
	bool b = std::is_trivially_default_constructible<Test>::value; // C++11 부터 가능
	bool b = std::is_trivially_default_constructible_v<Test>;      // C++17 부터 가능


	std::cout << b << std::endl;
}
