// 1�� �����ؿ�����
#include <iostream>
#include <type_traits>



template<typename T> void printv(const T& v)
{
	// if : �����Ͻ� false �� �Ǿ
	//		"���ø� ==> C++�Լ�" �� �����ȴ�.(�ν��Ͻ�ȭ)
	/*
	if ( std::is_pointer_v<T> ) // if ( false )
		std::cout << v << " : " << *v << std::endl; // �� �κе� C++ �Լ��� ����
	else
		std::cout << v << std::endl;
	*/

	// if constexpr : ������ false �϶��� �ش� ������ �ν��Ͻ�ȭ ���� ����� �ǹ�!
	// C++17
	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl; 
	else
		std::cout << v << std::endl;
}
// *v �� ������ ������ ���� ���� �ذ�å.
// 1. integral_constant - C++11
// 2. enable_if         - C++11
// 3. if constexpr      - C++17 - �� �ڵ� ����
// 4. concept           - C++20




int main()
{
	int n = 10;

	printv(n); // �� ��쿡 . error
}

