/* 3_forwarding_reference8
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

class Test
{
public:
	Test(int& arg){ arg = 100; }
};

template<typename T,typename ARG>
void make_shared(ARG&& arg)
{
	void *p = operator new(sizeof(T) );
	new(p) T(std::forward<ARG>(arg));
}

int main()
{
	int n = 10;
	make_shared<Test>(n);

	std::cout << n << std::endl;
}
