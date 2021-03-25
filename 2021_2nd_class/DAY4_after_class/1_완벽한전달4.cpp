#include <iostream>
void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
// main					chronometry						hoo(int&&)
// hoo(10)	===============================================> ok
// chronometry(10) =====> int&& arg
//						  hoo(arg) ========================> error. arg는 lvalue
//						  hoo(static_cast<int&&>(arg)   ===> ok. 

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10 에서 10은 rvalue 이지만 arg는 lvalue 입니다.
	//f(arg); // 이코드는 hoo(int&)를 찾게됩니다.!!

	// 해결책 : arg를 다시 rvalue로 변환해서 함수 호출
	f( static_cast<int&&>(arg) );
}

int main()
{
	hoo(10); 
	chronometry(hoo, 10); 
}
