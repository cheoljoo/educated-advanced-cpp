// 4번 소스-> 3번에 복사하세요
#include <iostream>

// 안드레이 알렉산더레스큐 - "페이스북"
template<int N> struct int2type
{
	enum { value = N };
};

int main()
{
	foo(0);
	foo(1); // 0, 1 모두 같은 타입(int)
			// foo(0), foo(1) 은 같은 함수 호출

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0, t1은 모두 다른 타입이다.
			 // foo(t0), foo(t1) 은 다른 함수 호출

			// 77, 78 은 같은 타입(int)
			// int2type<77>, int2type<78> 은 다른 타입
}
