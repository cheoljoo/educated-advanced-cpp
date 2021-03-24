
// 아주 중요합니다. 반드시 알아야 합니다
int main()
{
	int n = 10;

	// 1. non const lvalue reference 는 lvalue 만 가리킨다.
	int& r1 = n;  // ok
	int& r2 = 10; // error

	// 2. const lvalue reference 는 lvalue, rvalue를 모두 가리킨다.
	const int& r3 = n;  // ok
	const int& r4 = 10; // ok. temporary maturization 현상.
						// 이 순간 10을 가진 메모리가 생김..
//	const Point& r = Point(1, 2);

	// 3. C++11 에서는 상수성 없이 rvalue(임시객체) 를 가리키고 싶었습니다.
	// 왜?? "완벽한전달", "move" 등의 기술을 만들려면 임시객체의 상태 변경
	// 이 필요합니다. - 오후 주제
	// rvalue reference 는 rvalue 만 가리킬수 있다.
	int&& r5 = n; // error
	int&& r6 = 10; // ok
	//Point&& r = Point(1, 2);

}





