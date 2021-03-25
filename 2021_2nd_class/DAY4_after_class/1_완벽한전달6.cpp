#include <iostream>
void foo(int a, double b, char c) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

// 핵심. 완벽한 전달을 하려면
// 1. 인자를 받을때 "T&&" 를 사용
// 2. 인자를 다른곳에 보낼때는 "std::forward<T>(arg)"로 묶어서 전달
// 3. "가변인자 템플릿"을 사용해야 한다. - C++11

// 참고: 아래처럼 만들면
// Ts : 타입 하나가 아니라 여러개 타입을 가진 "템플릿 파라미터 팩"
//		int, double, char
// args : 10, 3.4, 'A'  가 있습니다. "함수 파라미터 팩" 이라고 합니다.
template<typename F, typename ... Ts> void chronometry(F f, Ts&& ... args)
{	
	f( std::forward<Ts>(args)... ); 
	// ... : 팩을 풀러 달라
	// f( std::forward<int>(10), std::forward<double>(3.4), std::forward<char>('A' ) )
}

int main()
{
	int n = 10;

	chronometry(foo, 10, 3.4, 'A'); 
	chronometry(goo, n);  

	std::cout << n << std::endl;
}



