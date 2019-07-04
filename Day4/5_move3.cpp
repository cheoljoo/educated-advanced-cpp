/*
- 
*/

#include <iostream>
#include <string.h>
//using namespace std;

/*
- 
*/

class People
{
    char* name;
    int age;
public:
    People(const char* n, int a): age(a)
    {
        name = new char[strlen(n) +1];
        strcpy(name,n);
    
    }
    ~People() { delete[] name; }

    // 깊은 복사로 구현한 복사 생성자
    People(const People& p) : age(p.age)
    {
        // 포인터 변수는 메모리 자체를 복사
        name  = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }

    // 임시 객체 (rvalue)인 경우 : 얕은 복사
    // foo() 임시 객체를 p로 받은 것임
    // name 자원을 이동한 것으로 "move 생성자"
    People(People&& p) : age(p.age) , name(p.name)
    {
        p.name = nullptr;  // 자원 포기
    }
};

People foo()
{
    People p("lee",30);
    return p;
}

int main()
{
    People p1("kim",10);
    
        // 얕은 복사
    People p2 = p1;         // 복사 생성

    People p3 = foo();      // move 생성자

    People p4 = static_cast<People&&>(p1);      // move
    People p5 = std::move(p2);  // 위처럼 캐스팅 하는 함수 
}
