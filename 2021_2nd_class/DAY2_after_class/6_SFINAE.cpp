// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

//void foo(int a) { std::cout << "int" << std::endl; }

//void foo(...)   { std::cout << "..." << std::endl; }


int main()
{
	foo(3); // 1. exactly matching - int
			// 2. template 을 사용해서 int 버전의 함수를 생성
			// 3. 가변인자( ...) 사용
}
