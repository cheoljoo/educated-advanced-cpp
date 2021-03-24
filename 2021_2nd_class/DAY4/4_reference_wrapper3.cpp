#include <iostream>
#include <functional>

void goo(int& a) { a = 100;}

// call by value를 사용하는 전달자 함수
template<typename F, typename T> void Caller(F f, T arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	Caller(goo, n );

	std::cout << n << std::endl;
}
