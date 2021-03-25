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

// reference_wrapper 를 생성하는 함수
template<typename T>
reference_wrapper<T> ref(T& obj)
{
	return reference_wrapper<T>(obj);
}


void goo(int& a) { a = 100; }

template<typename F, typename T> void Caller(F f, T arg)
{
	f(arg);
}
int main()
{
	int n = 10;

//	reference_wrapper<int> r(n); 
//	Caller(goo, r);

	Caller(goo, ref(n) ); // 

	std::cout << n << std::endl;
}







