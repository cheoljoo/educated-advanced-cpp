/* 4_temporary5
-  참조 캐스팅 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl;	// 20

	// Derived d를 Base 임시객체를 만들어 복사를 한다. 
	std::cout << static_cast<Base>(d).value << std::endl;	// 10

	// 임시객체를 만들지 않는다. 
	std::cout << static_cast<Base&>(d).value << std::endl;	// 10
	//static_cast<Base>(d).value = 100;	// error
	static_cast<Base&>(d).value = 100;	// ok

	// 값 캐스팅 : 임시객체 생성
	// 참조 캐스팅 : 임시객체 생성 안 함.
}
