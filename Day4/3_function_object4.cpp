/*
- lamba expression = 함수 객체 + 임시 객체
	- default 생성자는 없다.
	- 복사 생성자는 있다.
- cppreference.com
	- Closure 검색해보세요.
	- Closure : 람다표현식이 만드는 임시객체를 클로져 라고 한다. 
https://en.cppreference.com/w/cpp/language/expressions -> Lambda expressions
https://en.cppreference.com/w/cpp/language/lambda
*/

#include <iostream>
//using namespace std;

/*
- 
*/

template<typename T> void foo(T f)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	f(1,2);
};

int main()
{
	// C++11 lambda expression: 함수 객체인 임시 객체이다.
	foo( [](int a , int b){return a+b; } );


	// lambda expression은 
	// class xx { operator()(int,int) };  
	// xx();	// 인자에 객체가 들어가야 하므로 
	// 이런 class를 자동으로 만들어주고 임시 객체를 만든 것이다. 
	

	[](int a , int b){return a+b; }(1,2); 
		// lamba임시객체(1,2)
	
	auto f = [](int a , int b){return a+b; }; 
	f(1,2);

	//auto& a1 = [](int a , int b){return a+b; }; 		// 1
		// error : rvalue 
	const auto& a2 = [](int a , int b){return a+b; }; 	// ok
	auto&& a3 = [](int a , int b){return a+b; }; 		// ok : forwarding reference

	decltype(f) f2; 	// error
		// f랑 똑같이 만드는 변수 타입을 만들려는 것이다. 
		// f => class xx { operator()(int,int) };
		// 람다 표현식이 만드는 클래스는 디폴트 생성자가 없다. 
		// f의 default 생성자가 없어서 error
		//
		// C++20부터는 default 생성자를 만들어준다고함.
	decltype(f) f3(f);  // ok .. 복사 생성자는 있다.

	int n = 10;
	// int&& r=10;   rvalue reference
	// T&& r = 함수 인자;   우변에 따라 달라지는 forwarding reference
	auto&& a5 = 10;		// ok   int&& a5 = 10
	auto&& a6 = n;		// ok  	int& a6 = n
		// auto&& 은 우변에 따라 달라지는 forwarding reference이다. 
}
