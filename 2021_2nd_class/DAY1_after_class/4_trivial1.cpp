#include <iostream>

// trivial(자명하다) : 하는일이 뻔하다.!!(알려진대로 동작)
// 생성자     : 하는 일이 없다.
// 복사생성자 : 모든 멤버를 얕은 복사 할때.

// 1. 사용자가 만든 생성자가 없고
// 2. 가상함수가 없고
// 3. 기반 클래스가 없거나 기반 클래스의 생성자가 trivial 하고
// 4. 객체형 멤버가 없거나 기반 객체형 멤버 생성자가 trivial 하고
// "생성자를 trivial 하다" 라고 합니다.

class A
{
};

// B의 생성자가 trivial 할까 ?
class B //: public A
{
	//A a;
public:
	virtual void foo() {}
	B() {}
};




int main()
{
	// 생성자가 trivial 한 경우.. 생성자를 호출할 필요 없습니다.
	B* p = static_cast<B*>(malloc(sizeof(B)));

	// 이미 할당된 메모리에 생성자만 호출하는 문법- placement new 라고 합니다.
	new(p) B;  

	p->foo();
}





