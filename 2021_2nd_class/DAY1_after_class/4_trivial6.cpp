#include <iostream>
#include <type_traits> 

class Test
{
	int x = { 0 }; // 아래와 동일
	int y = 0; // 생성자를 만들고 초기화 리스트에 추가
			   // Test() : x{0}, y(0) {} 의 코드입니다.
public:
//	Test() {} // 사용자가 만든 생성자 - 컴파일러는 하는일이 있다고 생각 
			  // trivial 생성자 아님.
//	Test() = default; // 컴파일러에게 디폴트 생성자를 만들어 달라고 요청
					  // C++11
					  // trivial 생성자
};

int main()
{
	bool b = std::is_trivially_default_constructible<Test>::value; 

	std::cout << b << std::endl;
}
