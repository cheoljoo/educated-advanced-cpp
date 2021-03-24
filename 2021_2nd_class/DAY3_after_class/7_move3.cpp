#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

// 핵심 1. 클래스가 내부적으로 포인터 멤버가 있으면
//         디폴트 복사 생성자는 얕은 복사 현상이 있다.
//         반드시 사용자가 복사 생성자를 제공해야 한다.

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

	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1; // runtime error. 얕은 복사 문제.
}

