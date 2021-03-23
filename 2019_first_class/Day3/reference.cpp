/* 참고
-  const 위치에 따라 달라지는 ..
*/

#include <iostream>
//using namespace std;

/*
- 
*/

template<typename T> class Base
{
public:
	// a는 const 입니다. 
	virtual void foo(T const a)
	{
		std::cout << "Baee foo" << std::endl;
	}
};

class Derived : public Base<int*>
{
public:
	// foo 가상함수 재정의 해보세요.. override 사용하지 마세요
		// a를 따라가면 const
		// virtual void foo(const int* a) override    // compile시 error가 있었을 것임.
	// a 가 const 
	virtual void foo(int* const a)
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);  // "Derived foo" 나오게 해보세요.


	const int c1 = 10;
	int const c2 = 10;  // 이 2개는 같다. pointer가 아닐때는 같다.
	// pointer를 사용할때만 * 앞뒤 에 const를 붙이는 의미가 달라진다.
}
