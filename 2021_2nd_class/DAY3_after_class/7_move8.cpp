#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// rule of 0 : 자원관리를 직접 하지 않고, "자원 관리 클래스"를 사용해라.
//            복사, move를 모두 컴파일러가 지원한다.

// char* => string
// int*  => vector, shared_ptr<>
//
class People
{
	std::string name;
	int   age;
	std::string addr;
public:
	People(std::string name, int a, std::string addr = "unknown") 
		: name(name), age(a), addr(addr)
	{
	}
};

int main()
{
	People p1("kim", 20);

	p1 = p1; 


	People p2 = p1; 
	p2 = p1;		


	People p3 = std::move(p1);
	p3 = std::move(p2);

	p3 = std::move(p3); 
}
