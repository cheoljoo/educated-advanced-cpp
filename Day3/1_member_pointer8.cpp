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

// object Generator 라는 기술
// 클래스 템플릿을 직접 사용하지 말고 함수 템플릿을 통해서 만들자
	// C++11에서 함수 템플릿은 추론이 된다. 
// webkit source/wtf/wtf/scope.h 소스 참조
// 	makeScopeExit()
/* key : explicit && WTFMove
    explicit ScopeExit(ExitFunctionParameter&& exitFunction)
        : m_exitFunction(WTFMove(exitFunction))
    {
    }
 */
template<typename T>
IAction* makeAction( void(T::*handler)() , T* target) // C++11에서 함수 템플릿은 추론이 된다. 
{
	return new MemberAction<T>(handler,target);
};

IAction* makeAction(void(*handler)())
{
	return new FunctionAction(handler);
}

int main()
{
	//IAction* p1 = new FunctionAction(&foo);
	IAction* p1 = makeAction(&foo);
	p1->Execute();	// foo 실행 
	Dialog dlg;
	//IAction* p2 = new MemberAction<Dialog>(&Dialog::Close,&dlg);
	IAction* p2 = makeAction(&Dialog::Close,&dlg);
	p2->Execute();	
}




/*
// 함수 템플릿
square<int>(3);		// 정확한 표현
square(3);		// deduction : 템플릿 인자 생략 가능
// C++11에서 함수 템플릿은 추론이 된다. 


// 클래스 템플릿
list<int> s(10,3);
list s(10,3);		// C++17 부터는 템플릿 인자 생략 가능
			// C++14까지는 반드시 표기해야 한다.

*/
