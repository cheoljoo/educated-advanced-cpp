/* 3_forwarding_reference3
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/



int main()
{
	int n = 10;
	int& r = n;	// ok
	//int& & r2 = r;		// & & 이중 reference -> 이건 안됨. error
					// 직접 코드로 표현할 수 없다.

	using LREF = int&;
	using RREF = int&&;

	// typedef같은 것으로 정의 할때는 & & 사용가능하다. 
	// reference collapsing : 레퍼런스 붕괴
	LREF& ll = n ;		// & & => &    lvalue이므로 n
	LREF&& lr = n ;		// & && => &
	RREF& rl = n ;		// && & => &
	RREF&& rr = 10 ;		// && && => &&


}
