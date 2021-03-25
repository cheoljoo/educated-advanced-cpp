#include <iostream>
#include <functional>

// reference_wrapper 의 원리 : 결국 내부적으로 포인터를 보관하다가..
//						진짜 참조타입으로 암시적 변환될수 있는 도구

template<typename T> 
struct reference_wrapper
{
	T* obj;
public:
	reference_wrapper(T& p) : obj(&p) {}

	// 진짜 참조로 변환될수 있는 변환 연산자
	operator T&() { return *obj; }
};
int main()
{
	int n1 = 10;
	int n2 = 20;

	reference_wrapper<int> r1(n1);
	reference_wrapper<int> r2(n2);

	r1 = r2;

	// 진짜 참조 타입으로 암시적 변환되게 하자.!!
	int& r = r1; // r1.operator int&() 

	std::cout << n1 << std::endl;	
	std::cout << n2 << std::endl;	
	std::cout << r1 << std::endl;	// r1은 cout 과 연동되지 않지만
	std::cout << r2 << std::endl;	// 이순간 cout 으로 출력 가능한 변환이 있는지 찾게 된다.
}
