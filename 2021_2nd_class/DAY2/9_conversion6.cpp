#include <iostream>

// 람다 표현식과 함수포인터 변환

int main()
{
	int(*f)(int, int) = [](int a, int b) { return a + b; };
}
