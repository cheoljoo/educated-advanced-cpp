#include <iostream>
void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f( static_cast<int&>(arg) ); // 필요 없는 캐스팅 이지만 있어도 됩니다.
								 // 결국, 컴파일시 제거됩니다.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// T&& 를 사용하면 int&, int&& 의 함수를 자동생성할수 있다.
// 결국 아래 템플릿이 위의 2개의 함수를 생성하게 됩니다.
template<typename F, typename T> void chronometry(F f, T&& arg)
{
	// (인자로) lvalue 를(보내면) lvalue로 캐스팅하고
	// (인자로) rvalue 를(보내면) rvalue로 캐스팅하고
	// f(static_cast<T&&>(arg));

	f( std::forward<T>(arg) ); // std::forward 함수가 결국 위와 같은 캐스팅을 수행합니다.

//	std::move(arg); // arg를 무조건 rvalue로 캐스팅
		
//	std::forward : static_cast<T&&>(arg);
//	std::move    : static_cast<remove_reference_t<T>&&>(arg); 
}


int main()
{
	int n = 10;

	chronometry(foo, 10); // T=int   ===> static_cast<int&&>(arg) 이므로 rvalue로 캐스팅
	chronometry(goo, n);  // T=int&  ===> static_cast<int&>(arg)  이므로 lvalue로 캐스팅

	std::cout << n << std::endl;
}



