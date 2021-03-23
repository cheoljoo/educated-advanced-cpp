#include <iostream>

struct A
{
	int a;
	void fa() { std::cout << "fa : " << this << std::endl; }
};
struct B
{
	int b;
	void fb() { std::cout << "fb : " << this << std::endl; }
};
struct C : public A, public B
{
	int c;
	void fc() { std::cout << "fc : " << this << std::endl; }
};
int main()
{
	void(C::*f)(); // 멤버 함수 포인터 

	std::cout << sizeof(f) << std::endl; // 다중상속의 멤버 함수 포인터는
										// 32bit에서 크기가 "8" 바이트 입니다.
					// f = {함수주소, this의 offset값} 을 보관


//	f = &C::fa;   // f = { fa 주소, 0} 로 초기화
	f = &C::fb;   // f = { fb 주소, sizeof(A) } 로 초기화

	C obj;
	obj.fc();	// fc(&obj);

	(obj.*f)();	// f = &C::fa 라면 fa() 호출 ==> this 는 1000   fa(&obj)
				// f = &C::fb 라면 fb() 호출 ==> this 는 1004 .. ok..  fb(&obj + sizeof(A))
				// 그런데. 어떻게 1004가 나올까 ?

		// f.함수주소(&obj + f.this_offset)  의 원리로 호출
				

}




