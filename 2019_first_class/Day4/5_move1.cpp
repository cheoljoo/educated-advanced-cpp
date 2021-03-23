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
};

int main()
{
    People p1("kim",10);
    
        // 얕은 복사
    People p2 = p1;     
}
