/*1_member_pointer
- 
*/

#include <iostream>
#include <functional> 	// invoke	c++17
//using namespace std;

/*
- 핵심
	- 1. 일반함수 포인터에 멤버함수 주소를 넣을수 없다.
	- 2. 일반 함수 포인터에 static 멤버함수의 주소를 넣을수 있다.
	- 3. 멤버함수의 포인터를 만들고 사용하는 방법
	```cpp
	void(Dialog::*f2)() = &Dialog::Close; // ok
	Dialog dlg;
	(dlg.*f2)(); // ok
	(&(dlg)->*f2)();
	- 4. c++17 invoke 함수 
	```
*/

class Dialog
{
public:
	void Close() 	// voidClose(Dialog* this)
	{ 
		std::cout << "Close" << std::endl; 
	}
	static void Close2(){}
};
void foo() { std::cout << "foo" << std::endl; }


int main()
{
	void(*f1)() = &foo;	// ok 
	//void(*f2)() = &Dialog::Close; // error : 객체가 있어야 하기 때문
	void(*f3)() = &Dialog::Close2; // ok

	// 멤버함수를 가리키는 포인터 변수 만드는 모양
	// pointer to member
	void(Dialog::*f2)() = &Dialog::Close; // ok

	// f2();  // error . 객체가 없다.
	
	Dialog dlg;
	//dlg.f2();	// error : f2라는 함수를 찾을수 없다. 
	//
	//dlg.*f2(); 	//  .*  ->* : pointer to member operator
		// error : ()이 .*보다 우선순위가 높다.
	(dlg.*f2)(); // ok
	(&(dlg)->*f2)();


	std::invoke(f1);  // f1함수 호출
	// invoke(f1,10,20);  f1(10,20)
	std::invoke(f2,&dlg);  // (dlg.*f2)()의 의미

	// invoke (f2,&dlg, 10,20);  // (dlg.*f2)(10,20)
	
	// invoke에서는 함수가 member 함수 pointer인지를 조사하여 수행하는 것이다.
}
