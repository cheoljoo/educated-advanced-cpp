/* 3_forwarding_reference6
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

void foo(int&  arg){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
void foo(int&& arg){ std::cout << __PRETTY_FUNCTION__ << std::endl; }

//void forwarding(const int& n){ foo(n); }
//const도 안된다. 해결책은 함수 2개
void forwarding(int& n){ foo(n); }
void forwarding(int&& n){ 
	// main에서 10(rvalue)를 보냈는데
	// int&& n = 10으로 받으면서 lvalue가 되었다.
	// 즉 , value의 특성이 변경되었다.
	// 원래 rvalue로 캐스팅해서 전달해야 foo(int&&)이 수행된다. 
	foo( static_cast<int&&>(n) ); 
}

int main()
{
	int x = 10;
	forwarding(x);	// x를 foo에 보내고 싶다.
	forwarding(10);	// x를 foo에 보내고 싶다.
		// foo(int& 으로 간다
		// casting을 해서 int&&
		
	int&& n = 10;   // 10 : rvalue
			// n : lvalue
}
