/* 3_forwarding_reference12
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

struct Test
{
	int data ;

	// lvalue 객체에서만 부를수 있다. 
	void foo() & {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	// rvalue 객체에서만 부를수 있다. 
	void foo() && {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

int main()
{
	Test t; // 이름이 있습니다. 블럭을 벗어날때 까지 생존
		// 이름을 통해서 언제라도 접근 가능 . lvalue
	t.data = 10;

	t.foo();	// foo() &

	Test(); // 이름이 없습니다. 단일 문장에서만 사용. rvalue
		// 여기서는 즉시 파괴됨. 임시 걕체임
	//Test().data = 10; 	// error. 
	Test().foo();	// foo() &&

	Test&& r = Test(); // Test()의 수명이 r의 수명과 같이 가게 된다. 
			// r에 넣는 순간 , r은 lvalue이다.  
}
