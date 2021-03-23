/*
 * operator()
- 함수 객체의 장점 1. 상태를 가지는 함수
	- 일반 함수는 동작만 있고 상태는 가질수 없다.
	- 함수 객체는 클래스(구조체)이므로 멤버 데이터와 멤버 함수 활용 가능
*/

#include <iostream>
//using namespace std;

/*
-  함수는 동작은 있는데 상태가 없다.
	- 상태를 가지려면 global 변수가 필요하다. 
- 함수 객체의 장점은 동작뿐 아니라 , 상태가 있고,
	- 이 상태를 이용하여 많은 일을 할수 있다. 
*/

int Add(int a , int b){ return a+b;}

struct Plus
{
	int base;
	Plus(int a = 0) : base(a) {}
	int operator() (int a , int b){ return a+b+base; }
};
int main()
{
	Plus p(100);
	int n1 = Add(1,2); 
	int n2 = p(1,2);
}
