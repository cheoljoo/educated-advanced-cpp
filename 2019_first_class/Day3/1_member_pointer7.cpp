/* 1_member_pointer7
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

/*
- 모든 함수 pointer를 담을수 있는 pointer
	- void* 에는 member pointer를 못 담았다. 
*/

/*
 *   일반함수 포인터 : IAction with execute()
 *   멤버함수 포인터 : IAction with execute()
 */

void foo() { std::cout << "foo" << std:: endl; }

class Dialog 
{
public:
	void Close() { std::cout << "Dialog Close" << std::endl; }
};

struct IAction
{
	virtual void Execute() = 0;
	virtual ~IAction() {}
};

//일반 함수 포일터를 관리하는 클래스
class FunctionAction : public IAction
{
	typedef void(*HANDLER)();
	HANDLER handler;
public:
	FunctionAction(HANDLER h) : handler(h) {}

	virtual void Execute() override // C++11
	{
		handler();
	}
};



template<typename T> class MemberAction : public IAction
{
	using HANDLER = void(T::*)();	// C++11. typedef와 유사
	HANDLER handler;
	T* target;
public:
	MemberAction(HANDLER h ,T* t) : handler(h), target(t){}
	virtual void Execute() override 
	{
		(target->*handler)();
	}
};

int main()
{
	IAction* p1 = new FunctionAction(&foo);
	p1->Execute();	// foo 실행 
	Dialog dlg;
	IAction* p2 = new MemberAction<Dialog>(&Dialog::Close,&dlg);
	p2->Execute();	
}
