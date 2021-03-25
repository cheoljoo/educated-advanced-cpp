#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// Perfect forwarding : 인자를 다른곳에 보낼때 "손실/변화" 없이 완벽하게 전달하는기술

template<typename F, typename T> void chronometry(F f, const T& arg)
{
	// 시간 기록
	f(arg); // 함수 호출
	// 소요된 시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n);
	//foo(10);
	//goo(n);

	std::cout << n << std::endl;
}
