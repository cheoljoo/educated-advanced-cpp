/* 2_EBCO - 73 page
- EBCO : Empty Base Class Optimization
	- empty class가 기반 클래스가 되면 크기가 0으로 계산된다. 
	- c++ 표준의 unique_ptr이 이것을 사용한다.
	- 함수 객체는 거의다 empty : 기반클래스로 올린다. 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

class Empty {};

class AAA
{
	Empty a;
	int b;
};

// Empty가 상속이면 크기를 0으로 최적화 해준다.
class BBB : public Empty
{
	int b;
};

int main()
{
	std::cout << sizeof(AAA) << std::endl; // 8
	std::cout << sizeof(BBB) << std::endl; // 4
}
