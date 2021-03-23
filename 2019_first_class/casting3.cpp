// casting3.cpp
// reinterpret_cast : 포인터 <-> 포인터
// 			포인터 <-> 정수
// 			서로 다른 타입에 대한 참조
//
// memory 관련된 타입 캐스팅이 된다.  reference / point만 변환이 되는 것이다. 
#include <iostream>
#include <stdio.h>

using namespace std;
#if 0
int main()
{
	int n=10;
	double* p1 = static_cast<double*>(&n); // error
	double* p2 = reinterpret_cast<double*>(&n); // ok

	// 정수 => 포인터
	int* p3 = static_cast<int*>(10);	// error
	int* p4 = reinterpret_cast<int*>(10);	// ok

	// 참조
	char& r1 = static_cast<char&>(n); // error
	char& r2 = reinterpret_cast<char&>(n); // ok
	
	// 표준 타입의 값 형식 캐스팅
	double d1=n; // ok
	double d2 = reinterpret_cast<double>(n); //


}

#else

// 상속과 캐스팅
struct A { int a ; };
struct B { int b ; };
struct C : public A , public B{ int c ; };
int main()
{
	C cc;
	A* pA=&cc;		// 1000
	B* pB = &cc;		// 1004
	B* pB1 = (B*)&cc;		// 1004
	B* pB2 = static_cast<B*>(&cc);	// 1004
		// cc의 주소에서 B를 찾아라. 
		// B 가 없으면 에러, 있으면 B 주소 반환
		// compile할때 찾아라. 
		// &cc + sizeof(A)
		
	B* pB3 = reinterpret_cast<B*>(&cc);	// 1000
		// 단순 주소만 변환
		// cc의 주소를 무조건 B처럼 해석하겠다.  메모리의 재해석!
		// compile time 변환
	pB3->b=100;  // 결국 cc.a 에 넣게 됩니다.

	cout << & cc << endl;	// 1000
	cout << pA << endl; 	// 1000
	cout << pB << endl;	// 1004  because of int a => 1000 , int b => 1004
}
#endif
