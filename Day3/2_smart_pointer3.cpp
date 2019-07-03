/* 2_smart_pointer3
- 
*/

#include <iostream>
#include <memory>
//using namespace std;

/*
- 
*/
void foo(void* p){ free(p}; }

int main()
{
	// 삭제가 변경
	std::shared_ptr<int> p1(new int);	// p1의 소멸자에서 delete

	//std::shared_ptr<void> p2(malloc(100), 삭제자함수);
	std::shared_ptr<void> p2(malloc(100), foo);

	// 결국 관리 객체 안에 삭제자를 보관하게 됩니다. 
	//
	std::shared_ptr<void> p3(malloc(100), 
		[](void*p) { free(p); }   );
	
}


/*
-  4가지 관리 객체가 가지는 것
	- 참조계수  (strong count) : 객체 수명 관리
	- 삭제자
	- 객체 pointer
	- weak count : 관리 걕체 수명 관리 (weak pointer때문에) 
		- weak count == 0 일때 관리 객체도 지운다.
*/

