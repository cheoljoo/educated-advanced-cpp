// unevaluated2.cpp
#include <iostream>

class Test {};

int main()
{
	// 특정 타입에 특정 이름의 함수가 있는지 조사
	bool b = has_resize_function<Test>::value;
}