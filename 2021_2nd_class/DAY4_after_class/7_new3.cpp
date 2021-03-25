#include "cppmaster.h"
#include <vector>

// DBConnect 는 생성자에서 DB에 접속한다고 가정해 보세요
class DBConnect {};

int main()
{
	std::vector<DBConnect> v(5);

	v.resize(3); // 이순간 줄어든 2개를 위한 메모리는 계속 존재하지만
				 // 2개의 객체의 소멸자는 호출되어야 합니다.
				 // 소멸자의 명시적 호출이 필요 합니다.

	v.resize(4); // 늘어난 추가의 메모리는 이미 존재 합니다.
				 // 하지만, 생성자를 명시적으로 호출에서
				 // DB에 접속해야 합니다
				 // 생성자의 명시적 호출이 필요 합니다.
}






/*
int main()
{
	std::vector<int> v(10, 3);

	v.resize(7);  // 이 순간의 원리를 생각해 봅시다.

	std::cout << v.size()     << std::endl; // 7
	std::cout << v.capacity() << std::endl; // 10

	v.push_back(0); // 끝에 한개 추가

	std::cout << v.size()     << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10

	v.shrink_to_fit(); // 여분의 메모리 제거

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 8


	v.push_back(0); // 끝에 한개 추가 - VC : 12

	std::cout << v.size() << std::endl; // 9
	std::cout << v.capacity() << std::endl; // 12

//	st = [1, 2, 3, 4];
//	st.append(10) // 내부적으로 얼마나 늘리까요 ? 8
}
*/




