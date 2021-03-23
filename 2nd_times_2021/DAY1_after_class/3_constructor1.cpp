#include <iostream>

// 1. 기반 클래스 멤버의 생성자
// 2. 기반 클래스의 생성자
// 3. 파생 클래스 멤버의 생성자
// 4. 파생 클래스의 생성자

struct BM	  // Base Member
{
	BM()  { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};
struct DM   // Derived Member
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};

struct Base
{
	BM bm;
	//             컴파일러가 변경한 코드
	Base()        // Base() : bm()
	{
		std::cout << "Base()" << std::endl; 
	}
	~Base() { std::cout << "~Base()" << std::endl; }
};
//Base b;

struct Derived : public Base
{
	DM dm;

	Derived()  // Derived() : Base(), dm()    처럼 코드가 변경됩니다.
	{
		std::cout << "Derived()" << std::endl; 
	}
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
	// 아래 코드의 결과를 예측해 보세요.
	Derived d;
}
