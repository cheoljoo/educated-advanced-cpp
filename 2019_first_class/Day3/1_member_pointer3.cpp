/* 1_member_pointer3
- This is code for Windows
*/

#include <iostream>
#include <memory>
#include <pthread.h>
//using namespace std;

/*
- 
*/

/*
-  std::enable_shared_from_this : this 포인터로 외부에서 만든 관리 객체를 공유할수 있게 하는 기반 클래스
*/
// CRTP
class Thread : public std::enable_shared_from_this<Thread>
{
	std::shared_ptr<Thread> holdme;
public:
/*
- 아래 코드는 2개의 문제가 있습니다. 
	- 1. raw pointer(this)를 가지고 초기화하면 관리객체가 따로 만들어집니다.
	- 2. 생성자에서 초기화하면 관리객체를 같이 사용할때 참조계수가 즉시 2가 됩니다.
	```cpp
	Thread() : holdme(this)
	{
	}
	```
*/
	
	// shared_from_this() : 외부에 만들어져있는 shrad_ptr용 관리 객체를 같이 사용하게 하는 함수 
	// 	std::enable_shared_from_this의 member function
	Thread() // : holdme(shared_from_this())
	{
	}

	~Thread(){
		std::cout << "~Thread" << std::end;
	}

	void run() { 
		holdme(shared_from_this();
		CreateThread(0,0,threadMain,this,0,0); 
	}

	static DWORD __stdcall threadMain(void* p)	// p => this
	{
		Thread* self = static_cast<Thread*>(p);


		// A.아래의 holdme.reset()을 하지 않는 경우도 고려하여 , 
		// 지역변수로 스마트 포인터를 다시 생성한다. 
		//
		// Thread.cpp 에도 strong을 쓰고 뒤에 즉시 clear()나 reset()해주는 코드가 있다. -1
		//
		// android에서는 객체 안에 관리 객체가 있다. 그러므로 emable_shared.. 를 사용할 필요가 없다. 
		//
		std::shared_ptr<Thread> string(self->holdme);		// 참조계수 3
		self->holdme.reset(); 	// 참조계수 2

		self->threadLoop();
		
		/*
		 * 위의 A case와 같이 하면 이 code가 필요하지 않다.
		 * 이유는 여기까지 도달하지 못할수도 있다. 
		 *
		// 자신의 참조계수를 가지고 있던 smart pointer를 reset 합니다.
		self->holdme.reset();
		*/

		return 0;
	}
	virtual void threadLoop() = 0;
};

class MyThread : public Thread 
{
	int data = 0;
public:
	// thrad가 하고 싶은 일
	virtual void threadLoop()
	{
		std::cout << "MyThread" << std::endl;
		data = 10;
	}
};

int main()
{
	//MyThread* p = new Thread;
	//p->run();
	
	{
		// MyThread가 먼저 만들어지고 , sp가 만들어진다.
		// MyThread안에서 sp에 대한 처리를 하는데 , sp는 아직 안 만들어져있는 상태이다. 
		// homeme를 생성자에 놓지 말고 , run() 안으로 넣어야 한다. 
		std::shared_ptr<MyThread> sp(new MyThread);
		sp->run();
	}		// smart pointer를 사용하면 파괴되어 loop가 수행되는 thread는 에러 발생

	getchar();
}
