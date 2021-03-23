#include <iostream>
#include <type_traits>

class Test
{
    int x;
    int y;
public:
    //Test(){}
    Test() = default;
};
int main()
{
	bool b = std::is_trivially_default_constructible_v<Test>;

	std::cout << b << std::endl;
}
