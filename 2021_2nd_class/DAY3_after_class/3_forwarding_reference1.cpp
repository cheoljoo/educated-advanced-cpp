
// 아주 중요 합니다. 
// 함수 인자로
// int&  : 정수형 lvalue 만 받을수 있다.
// int&& : 정수형 rvalue 만 받을수 있다.
// T&    : 임의 타입의 lvalue 만 받을수 있다.

// T&&   : 임의 타입의 lvalue 와 rvalue를 모두 받는다.
//	       lvalue를 받는 함수 생성
//         rvalue를 받는 함수 생성

// f4(n)  : T=int&     T&&=int& &&     최종함수 : f4(int& )
// f4(10) : T=int      T&&=int&&       최종함수 : f4(int&& )
// 최종 함수는  "call by reference" 를 사용하게 된다.

// "universal reference" 라고 부르자고 "effective-c++" 의 저자가 제안
// "forwarding reference" 라고 부르기로 결정




void f1(int&  r) {}
void f2(int&& r) {}

template<typename T> void f3(T& a)
{
}
int main()
{
	int n = 10;

	// 1. 사용자가 타입을 전달하는 경우
	f3<int>(n);    // T=int		T&=int&			f3(int& a )
	f3<int&>(n);   // T=int&	T&=int& &		f3(int& a )
	f3<int&&>(n);  // T=int&&	T&=int&& &		f3(int& a )

	// 2. 사용자가 타입을 전달하지 않으면 컴파일러가 인자를 보고
	//	  함수를 생성하기 위해서 T를 결정합니다.
	f3(10); // T를 int, int&, int&& 중 어떠한 것으로 결정해도 받을수 없다.
			// 컴파일 에러.
	f3(n);  // T=int 로 결정!
}











template<typename T> void f4(T&& a)
{
}
int main()
{
	int n = 10;

	// 1. 타입을 명시적으로 전달하는 경우
	f4<int>(10);   // T=int       T&&=int&&        f4(int&& a)
	f4<int&>(n );  // T=int&      T&&=int& &&      f4(int&  a)
	f4<int&&>(10); // T=int&&     T&&=int&& &&     f4(int&& a)

	// 2. 타입을 전달하지 않은 경우. 인자를 보고 컴파일러가 T의 타입 결정
	f4(n);  // T=int& 로 결정. 최종 함수 모양 f4(int&)
	f4(10); // T=int  로 결정. 최종 함수 모양 f4(int&& a) 
}




