#include <iostream>
#include <functional> 

// 함수 대신 함수객체를 인자로 보낼때
// F f : 복사본 생성이 오버헤드
// F& f: rvalue(임시객체)를 받을수 없다.
// const F& f :  f.operator()(1, 2) 호출에서 ()연산자가 반드시 상수함수이어야 한다.
//				()연산자가 상수멤버 함수가 아니면 에러

template<typename F, typename ... Ts>
decltype(auto) chronometry(F&& f, Ts&& ... args)
{
	return std::invoke(f, std::forward<Ts>(args)...);
}

// Callable Object : ()를 사용해서 호출 가능한 모든 것들
//					함수, ()연산자를 재정의한 클래스, 함수 포인터, 멤버함수 포인터,람다표현식
//							(함수객체)
struct Add
{
	// 장점 : 멤버 데이타 활용가능
	int count = 0;

	int operator()(int a, int b) //const
	{
		++count;			// 함수 호출 횟수 파악. 일반함수로 될까요 ?
		return a + b;
	}
};

int main()
{
	Add add;
	int n = add(1, 2); // add.operator()(1, 2)의 원리
}



