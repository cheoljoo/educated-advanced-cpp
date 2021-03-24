// 레퍼런스3.cpp
using LREF = int&; // typedef int& LREF;
using RREF = int&&;

int main()
{
	int n = 10;

	int& r = n;
//	int& & rr = r; // error. 포인터의 포인터는 만들수 있지만
					// 참조의 참조는 만들수 없다.

	LREF r1 = n;
	RREF r2 = 10;
	//------------------
	// 타입 추론 과정에서 레퍼런스 충돌이 나오면 아래의 규칙으로 타입결정
	// "reference collapsing" 규칙 적용
	LREF&  r3 = n ; // int&  &   ==> int&
	RREF&  r4 = n ; // int&& &   ==> int&
	LREF&& r5 = n ; // int&  &&  ==> int&
	RREF&& r6 = 10 ; // int&& &&  ==> int&&

}
