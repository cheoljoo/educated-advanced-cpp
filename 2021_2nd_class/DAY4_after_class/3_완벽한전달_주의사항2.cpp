// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}
void foo() {}
void foo(int a) {}
void foo(int a, int b) {}

int main()
{
	// 함수를 직접 호출하면 ok
	foo();
	foo(10);

	// 그런데...
	//chronometry(foo, 1); // error. 어떤 foo인지 알수 없다.

	chronometry(static_cast<void(*)(int)>(foo), 1); // ok.. 컴파일러가 함수를 찾을수 있도록
													// 함수 모양의 정보를 알려준다.
												// 일반적으로 캐스팅 모양 사용
}









