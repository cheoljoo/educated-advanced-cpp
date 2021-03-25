#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

// 완벽한 전달의 조건
// 1. 복사본이 있으면 안된다.
// 2. 기존 메모리에 const등의 속성이 추가되어도 안된다.
// 3. int&, int&&, const int& 등의 버전을 따로 제공해야 한다.
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
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n);

	std::cout << n << std::endl;
}
