#include <iostream>
#include <vector>
#include <initializer_list>
class Point
{
	int x, y;
public:
	Point(int a)        { std::cout << "1" << std::endl; }
	Point(int a, int b) { std::cout << "2" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "3 " << std::endl; }
};
int main()
{
	Point p1(1);	// 1번 생성자
	Point p2(1,2);	// 2번 생성자

	Point p3( { 1, 2 } ); // 3번 생성자
	Point p4{ 1,2 }; // 3번 생성자, 없으면 2번생성자
	
	Point p5(1,2,3); // error. int 가 3개인 생성자는 없다.

	Point p6{ 1,2,3 };    // 3번 생성자 호출
	Point p7 = { 1,2,3 }; // 역시 3번 생성자 호출

	// 핵심 : 생성자 인자로 std::initializer_list<int> 를 받으면 
	//			동일 타입의 "가변 갯수"의 인자를 보낼수 있다.
	// 왜..!! STL을 아래 처럼 사용하게 해주고 싶었다.
	std::vector<int> v1{ 1,2,3,4,5,6,7,8,9,10 }; // ok
	std::vector<int> v2 = { 1,2,3,4,5,6,7,8,9,10 }; // ok

	// 주의!! 아래 2줄의 차이점은 반드시 알아야 합니다.
	std::vector<int> v3( 10, 2 ); // int 2개인 생성자. 
								  // 10개의 요소를 2로 초기화
	std::vector<int> v4{ 10, 2 }; // std::initializer_list<int> 생성자
								  // 2개를 10, 2로 초기화
}

