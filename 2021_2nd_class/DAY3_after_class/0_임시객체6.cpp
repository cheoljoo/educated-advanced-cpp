#include <iostream>

class Test
{
public:
//	void foo() { std::cout << "foo" << std::endl; }

	// 멤버 함수 만들때, 임시객체와 아닌 경우에 사용할 함수를 분리해서 만들수 있습니다.
	void foo() &  { std::cout << "foo & " << std::endl; }  // 이름 있는 객체일때
	void foo() && { std::cout << "foo && " << std::endl; } // 임시 객체 전용
};

int main()
{
	Test t;
	t.foo();

	Test().foo();
}
