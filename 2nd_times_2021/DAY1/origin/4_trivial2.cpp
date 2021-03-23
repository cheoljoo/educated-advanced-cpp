#include <iostream>
#include <type_traits>

class Test
{
public:
	virtual void foo() {}
};
int main()
{
	bool b = std::is_trivially_default_constructible_v<Test>;

	std::cout << b << std::endl;
}
