#include <iostream>

// 핵심 1. 평가되지 않은 표현식에 넣는 함수는 선언만 있으면 가능
//      2. sizeof(함수호출식) 으로 어느 함수가 호출되는지 조사 가능.

int  check(int a);
char check(double d);

int main()
{
	int n = sizeof( check(3.4) );

	std::cout << n << std::endl; // 1
}