#include <iostream>
#include <functional>

// C++의 참조 : 값이 이동하는 참조
//				참조 자체는 변경될수 없다. (상수처럼 동작)

// reference_wrapper : 이동 가능한 참조
//					대입연산시 참조가 이동

int main()
{
	int n1 = 10;
	int n2 = 20;

//	int& r1 = n1;
//	int& r2 = n2;
	std::reference_wrapper<int> r1(n1);
	std::reference_wrapper<int> r2(n2);
	r1 = r2; 

	// 아래 코드의 결과를 예측해 보세요 C++ 참조
	std::cout << n1 << std::endl;		// 20   10
	std::cout << n2 << std::endl;		// 20   20
	std::cout << r1 << std::endl;		// 20   20
	std::cout << r2 << std::endl;		// 20   20
}
