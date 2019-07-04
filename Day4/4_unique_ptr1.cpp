/*
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

class Car
{
public:
	void Go(){ std::cout << "Car Go" << std::endl;}
	virtual ~Car(){ std::cout << "~Car" << std::endl;}
};

/*
- 스마트 포인러를 만들어봅시다.
- 핵심 : -> 와 *를 재정의하여 포인터 처럼 보이게 하는 것
- 장점 : raw pointer가 아니라 객체이므로 자동소멸 / 자동 삭제 가능하다. 
*/
class unique_ptr
{
	Car* obj;
public:
	unique_ptr(Car* p = 0) : obj(p) {}
	virtual ~unique_ptr() { delete obj; }

	Car* operator->(){ return obj; }
	Car& operator*(){ return *obj; }
};

int main()
{
	unique_ptr p1(new Car);
	p1->Go(); 
		// (p1.operator->())Go()
		// (p1.operator->())->Go()

	(*p1).Go();	// p1.operator*
}
