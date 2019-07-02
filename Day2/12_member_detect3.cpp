/* 12_member_detect1 143 page
- 
*/

#include <iostream>
#include <type_traits>
#include <vector>
#include <array>
#include <complex>

class Point
{
	int x, y;
public:
	//Point() {}
	Point(int a,int b):x(a),y(b) {}
	int foo() { return 0; }
};

// Point& declval();	// 핵심 : 구현은 없습니다. 
template<typename T> T& declval();

int main()
{
	//int n = sizeof( Point().foo() );	// 4
		// default 생성자가 있다고 가정

	//int n = sizeof( declval().foo() );	// 4
	
	//int n = sizeof( declval<Point>().foo() );	// 4
	
	int n = sizeof( std::declval<Point>().foo() );	// 4
		// 평가되지 않는 표현식에서 함수의 사이즈를 알고 싶다면... 이것을 사용

	std::cout << n << std::endl;
}

