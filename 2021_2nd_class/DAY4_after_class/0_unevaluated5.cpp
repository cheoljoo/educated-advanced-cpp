#include <iostream>

class Test
{
public:
	Test(int a) {}

	void resize() {}
};

// declval() : 리턴타입이 "T" 인 함수 입니다.
//			  평가되지 않은 표현식에서만 사용하려고 만들었기 때문에 
//			  구현부는 필요 없습니다.
//				C++ 표준에 이미 있습니다.
template<typename T> T declval();

// T.resize() : Test.resize()
// declval<T>().resize()
//template<typename T> int  check(decltype(T().resize())* p);

template<typename T> int  check(decltype(std::declval<T>().resize())* p);



template<typename T> char check(...);

int main()
{
	int n = sizeof(check<Test>(0)); // 이순간 어느 함수가 호출되는지를 조사. 

	std::cout << n << std::endl;
}



