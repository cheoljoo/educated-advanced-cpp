// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

void foo(int* p) {}

int main()
{
	foo(0); // ok   0은 포인터로 암시적 변환되지만
	int n = 0;
	foo(n); // error.. 0을 가진 정수 변수 n은 포인터로 변환될수 없다

	// 아래 코드 생각해 보세요
	chronometry( foo, 0 );

	// C++11 부터는 포인터 의미로 0을 사용하지 말고 nullptr을 사용하자.
	foo(nullptr); // ok
	chronometry(foo, nullptr); // ok,   T=nullptr_t 로 결정된다.
								// nullptr_t arg = nullptr;
								// foo(arg);  가 되는데.. nullptr_t 타입의 모든 변수는
								//						포인터로 암시적 변환 될수 있다.


}









