#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }

	// 깊은 복사로 구현한 "복사 생성자"
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
	// 임시객체를 위한 복사 생성자를 
	// 별도로 제공하자.
	// "move 생성자라고 합니다."
	/*
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr; // 원본 객체의 자원포인터 reset
						// 이 코드가 되려면 임시객체도
						// 상태를 변경할수 있어야합니다.
	}
	*/
};

Cat foo()
{
	Cat c("yaong", 5);
	return c;
}

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// 복사 생성자 호출
	Cat c3 = foo(); // move 생성자 호출

	Cat c4 = static_cast<Cat&&>(c1); //  move 생성자를 호출하기 위해 
									// lvalue 를 rvalue로 캐스팅 한다.

	Cat c5 = std::move(c3); // 이  표준 함수가 위처럼 캐스팅하고 있습니다.
	// 결국 : std::move()는 캐스팅에 불과 하고 
	//        캐스팅 결과로 "move 생성자"가 호출되는데
	//		  move 생성자 안에서 자원을 이동하는 코드를 만들어야 합니다.
	
}
// 사용자가 std::move(c) 했는데.. Cat 안에
// 1. move 생성자가 있으면 사용 - 빨라진다.
// 2. move 생성자가 없으면 "복사 생성자"를 사용한다. - 성능향상을 볼수 없지만
//						에러는 없다..

// g++ 은 임시객체 생성을 하지 않은 최적화가 되는 경우가 많습니다.
// g++ 소스.cpp -fno-elide-constructors   옵션 주세요..


