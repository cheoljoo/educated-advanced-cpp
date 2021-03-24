#include <iostream>

class Test 
{
public:
//	void resize() {}
};

template<typename T> int  check( ? );
template<typename T> char check(...);

int main()
{
	int n = sizeof( check<Test>(0) );

	std::cout << n << std::endl;
}



