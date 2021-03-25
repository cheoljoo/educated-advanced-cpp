#include <iostream>
void foo(int a) {}
void goo(int& a) { a = 100; }

// 이코드는 한가지의 문제점이 있습니다. 아래 hoo를 생각해 보세요
void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok
	chronometry(hoo, 10); // error  <<==== 여기서 에러가 나는 것이 문제
						// 원인과 해결책은 다음소스에서..


	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n);

	std::cout << n << std::endl;
}
