/* 3_forwarding_reference9
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

template<typename T> class Test
{
public:
	// 아래 코드는 forwarding reference일까요?
	// 아닙니다.
	// 클래스가 템플릿이지 함수 자체가 템플릿이 아닙니다.
	// 클래스 생성시 이미 T 타입이 결정됩니다. 
	// 그래서 , forwarding reference가 아닙니다. 
	void foo(T&& arg){}

	// 아래 코드가 forwarding reference 입니다.
	template<typename U> void goo(U&& arg) {}
};

int main()
{
	int n = 0;
	Test<int> t;
	t.foo(10);
	t.foo(n);

}
