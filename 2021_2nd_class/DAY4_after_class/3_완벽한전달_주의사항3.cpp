// 완벽한 전달 주의사항3
#include <iostream>
#include <functional>
using namespace std::placeholders;
void foo(int a, int& b) { b = 100; }

int main()
{	
	//  C++11 에서 추가된 함수포인터와 유사한 기능의 템플릿
	std::function<void(int)> f;

//	{
		int n = 10;

		// std::bind : 인자가 N 개인 함수의 일부 인자를 고정한 새로운 함수를 만드는 도구
		//             파이썬의 "functools.partial()"
		f = std::bind(foo, _1, n); // 1. n 자체를 보관하고 있을것이다.
								   // 2. n의 값인 10을 내부변수 보관하고 있을것이다.

		f = std::bind(foo, _1, std::ref(n) ); // n을 참조로 고정해 달라는것.

//	}

	f(0); // foo(0, n)

	std::cout << n << std::endl;
}