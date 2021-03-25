#include <iostream>
#include <functional> // std::invoke()

class Test
{
public:
	int& foo(int& a, double b)
	{
		a = 100;
		return a;
	}
};

template<typename F, typename ... Ts>
decltype(auto) chronometry(F f, Ts&& ... args)
{

	return std::invoke(f, std::forward<Ts>(args)...);
}
// /std:c++latest


int main()
{
	int n = 0;
	Test t;
	int& ret = chronometry(&Test::foo, &t, n, 3.4);

	ret = 300;
	std::cout << n << std::endl; // 300
}



