#include "cppmaster.h"
#include <vector>

class Point
{
	int x, y;
public:
	Point(int* a, int& b) { LOG_FUNCTION_NAME(); }
	~Point()            { LOG_FUNCTION_NAME(); }
	Point(const Point&) { LOG_FUNCTION_NAME(); }
};
int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// 1. 
	//Point pt(1, 2);
	//v.push_back(pt);

	// 2. 임시객체를 전달해서 넣기
	//v.push_back( Point(1, 2) );

	// 3. 객체를 전달하지 말고..
	//    객체를 만들기 위한 생성자 인자를 전달한다.
	int n = 0;
	//v.emplace_back(0, n); 
	v.emplace_back(nullptr, n);
				// emplace_back() 함수가 내부적으로
				// new Point(0, n) 를 수행..

	// STL 컨테이너에
	// 사용자 정의 타입을 값으로 보관하려면
	// push_xxx 대신 emplace_xxx 를 사용해라
	// push_front => emplace_front
	// push_back  => emplace_back
	// insert     => emplace


	std::cout << "-----" << std::endl;
}




