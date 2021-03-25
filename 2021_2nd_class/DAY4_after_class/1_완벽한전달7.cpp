#include <iostream>

/*
int n = 10;
int& r = n; 
auto a1 = r; // r은 참조 지만 auto 는 우변의 참조와 const 를 버리고 타입결정
			 // 그래서 "int a1 = r"
decltype(auto) a2 = r; // 우변의 타입과 정확히 같은 타입으로 결정
						// int& a2 = r
*/
int& foo(int& a, double b, char c) { a = 100; return a; }

// 원본 함수의 반환 값도 완벽하게 반환해야 합니다.

template<typename F, typename ... Ts> 
decltype(auto) chronometry(F f, Ts&& ... args)
{
	return f(std::forward<Ts>(args)...);
}


int main()
{
	int n = 10;

	int& ret = chronometry(foo, n, 3.4, 'A');
	ret = 300; 
	std::cout << n << std::endl; // 300
}



