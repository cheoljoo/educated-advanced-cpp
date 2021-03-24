#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// 클래스 안에 포인터가 있고 자원할당을 하고 있다면
// 3개의 함수가 추가로 필요 하다(소멸자, 복사생성자, 대입연산자)

// rule of 3 : 소멸자, 복사생성자, 대입연산자  - C++98
// rule of 5 : 소멸자, 복사생성자, 대입연산자, move 생성자, move 대입 연산자 - C++11

class People
{
	char* name;
	int   age;
public:
	People(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
	}
	~People() { delete[] name; }

	People(const People& p) : age(p.age)
	{
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);

		std::cout << "복사생성자" << std::endl;
	}
	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		std::cout << "복사 대입연산자" << std::endl;
		age = p.age;

		delete[] name;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);

		return *this;  
	}

	People(People&& p) : age(p.age), name(p.name)
	{
		p.name = nullptr;
		std::cout << "move 생성자" << std::endl;
	}

	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		std::cout << "move 대입연산자" << std::endl;
		age = p.age;

		delete[] name;
		name = p.name;
		p.name = nullptr;

		return *this;
	}
};
int main()
{
	People p1("kim", 20);

	People p2 = p1; // 복사 생성자
	p2 = p1;		// 대입 연산자

	People p3 = std::move(p1);
	p3 = std::move(p2);		  
}




