int x = 10;
int foo()  { return x; } // x의 값의 반환 - 10		
int& goo() { return x; } // x의 메모리 정보 반환    

// lvalue : 등호의 양쪽에 올수 있다.
//			값과 "이름"이 있다. 
//			단일식을 넘어서 사용가능.
//			주소연산자로 주소를 구할수 있다.
//			"참조를 반환하는 함수"

// rvalue : 등호의 오른쪽에만 올수 있다.
//			값만 있고, 이름이 없다.
//			단일식에서만 사용가능
//			주소연산자로 주소를 구할수 없다.
//			"값을 반환하는 함수" 
//			리터럴(10, 3.4), "임시객체(temporary)"

int main()
{
	int v1 = 10, v2 = 10;

	v1 = 20;	// v1 : lvalue,  20 : rvalue 
	10 = v1;	// error. 10는 lvalue 가 될수 없다.
	v2 = v1;

	int* p1 = &v1;
	int* p2 = &10; 

	foo() = 20; // 10 = 20 의 의미 error
	goo() = 20; // x메모리 = 20 .. ok.

	//
	const int c = 10;
	c = 20;				// c 는 lvalue ? rvalue  ?
						// 수정불가능한 lvalue, immutable lvalue

	// 질문 2. 모든 rvalue는 상수 이다. 임시객체는 상수가 아니다.
//	Point(1, 2).x = 10; // error
//	Point(1, 2).set(10, 20); // ok  즉, 멤버 함수를 사용하면 객체 상태 
							// 변경가능.
}









