#include <iostream>

// 결론 : 임시객체는 
// 1. 사용자가 명시적으로 만들수도 있고 ==> 함수 호출시 인자로 전달  foo( Point(1,2))

// 2. 사용자가 만든 코드에 의해 암시적으로 생성되기도 한다.
//    (A) 값타입으로 반환하는 함수
//    (B) 값타입으로 캐스팅할때 

// 임시객체는 성능저하나 버그의 원인이 될수 있으므로 언제 생성될지 정확히 알고 있어야 한다



struct Base
{
	int value = 10; 

	Base()  { std::cout << "Base()" << std::endl; }
	Base(const Base& b) : value(200)  { std::cout << "Base()" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl;  // 20
	std::cout << d.Base::value << std::endl;  // 10

	std::cout << "-------------" << std::endl;
	std::cout << static_cast<Base>(d).value << std::endl;  // 10
	std::cout << "-------------" << std::endl;
	std::cout << static_cast<Base&>(d).value << std::endl;  // 10

//	static_cast<Base>(d).value = 20;  // error
//	static_cast<Base&>(d).value = 20; // ok

}

