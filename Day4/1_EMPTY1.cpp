/* 1_EMPTY1  - 73 page
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

// empty class : non static 멤버 데이터가 없는 클래스
// static member는 있어도 됨.
// 크기가 1로 정의함.
struct AAA
{
};

int main()
{
	AAA aaa;
	std::cout << sizeof(aaa) << std::endl;	// 1
} 
