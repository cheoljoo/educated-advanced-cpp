/*
- 구조체를 함수처럼 사용할수 있으면 함수 객체라고 한다.
*/

#include <iostream>
//using namespace std;

/*
- 
*/

int Add(int a , int b){ return a+b;}
struct Plus
{
	int operator() (int a , int b){ return a+b; }
};
int main()
{
	Plus p;
	int n1 = Add(1,2); // ok
	int n2 = p(1,2);	// p.operator()(1,2)

	// a+b;   // a.operator+(b)
	// a();	  // a.operator()()    ()연산자를 호출하라
	// a(1,2); // a.operator()(1,2)
}
