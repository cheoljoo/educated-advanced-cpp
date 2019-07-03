/* 1_member_pointer2
- 
*/

#include <iostream>
#include <pthread.h>
//using namespace std;

/*
- 
*/

/*
DWORD __stdcall foo(void* p)
{
	return 0;
}

int main()
{
	pthread_create();
}
*/

// thrad 개념을 담은 클래스
// 아래 코드를 library 내부 클래스라고 생각하세요.
class Thread
{
public:
	void run() { pthread_create(0,0,threadMain,this,0,0); }

	// 핵심 1. 아래 함수는 반드시 static 멤버 함수가 되어야 합니다. 
	// static이면 첫번째 인자로 this가 오지 않습니다. 
	// static으로 하지 않으려면 class 밖으로.. 
	//
	// 안드로이드소스 /platform_system_core/libutils/include/utils/Thread.h
	// https://android.googlesource.com/platform/system/core/+/android-5.0.0_r2/include/utils/Thread.h
	//     static이 한개 존재하게 된다. 
	//     static int _threadLoop(void* user)  this가 될 것이다.
	//     _theadLoop() 처음에 stati_cast를 하여 사용한다.
	static DWORD __stdcall threadMain(void* p)	// p => this
	{
		Thread* self = static_cast<Thread*>(p);
		//threadLoop();		// static이 되면 this가 없어서 theadLoop를 수행 못한다.

		// self가 결국 this입니다.
		// self를 사용하면 static member function에서도 다른 멤버에 접근할수 있습니다. 
		self->threadLoop();
		return 0;
	}
	virtual void threadLoop() = 0;
};

// 아래 클래스는 사용자 클래스 입니다.
class MyThread : public Thread 
{
public:
	virtual void threadLoop()
	{
		std::cout << "MyThread" << std::endl;
	}
};

int main()
{
	MyThread mt;
	mt.run();  // 이 순간 새로운 thread가 생성되어 threadLoop()를 실행해야 합니다.
	getchar();
}
