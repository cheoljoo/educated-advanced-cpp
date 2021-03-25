#include <iostream>
#include <functional>

template<typename T>
struct reference_wrapper
{
	T* obj;
public:
	reference_wrapper(T& p) : obj(&p) {}

	// 진짜 참조로 변환될수 있는 변환 연산자
	operator T&() { return *obj; }
};

void goo(int& a) { a = 100;}
// 
// call by value(값 타입을) 사용하는 완벽한 전달자 함수
template<typename F, typename T> void Caller(F f, T arg)
{
	f(arg);
}
int main()
{
	int n = 10;

	//Caller(goo, n ); // n의 값 전달
	//Caller(goo, &n);  // n의 메모리 정보(주소)전달
					  // 하지만 int* 는 int&로 변환될수 없다.

	reference_wrapper<int> r(n); // r은 내부적으로 n주소 보관
	Caller(goo, r);

	std::cout << n << std::endl;
}
