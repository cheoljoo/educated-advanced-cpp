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
	C obj;
	A* pA = &obj;
	B* pB = &obj;
//	std::cout << &obj << std::endl; // 1000 일때
//	std::cout << pA << std::endl;	// 1000
//	std::cout << pB << std::endl;   // 1004 

	obj.fc(); // 1000 => fc(&obj)
	obj.fa(); // 1000 => fa(&obj)
	obj.fb(); // 1004 => fb(&obj + sizeof(A)) 의 원리로 호출됩니다.
}




