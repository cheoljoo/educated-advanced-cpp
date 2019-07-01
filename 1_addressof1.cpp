// 1_addressof1.cpp  : 7 page
#include <iostream>
using namespace std;

class Point
{
	int x,y;
public:
	// 내 조소를 알지 말라 기법 
	// 주소를 나타낼때는 0대신 nullptr을 사용하자 - c++11
	Point* operator&() const { return nullptr; }
};

int main()
{
	Point pt;
	cout << &pt << endl; 	// pt.operator&()

	Point* p = reinterpret_cast<Point*>(&pt);	// 이미 &을 불렀으므로 0
	//Point* p1 = &(reinterpret_cast<Point>(pt));	// error. 값 캐스팅
	
	Point* p1 = reinterpret_cast<Point*>( &(reinterpret_cast<char&>(pt)) );	// ok
		// char로 일반 변환해야 Point&로 먹지 않게 된다.  그래서 일단 char&으로 변환하여 다시 Point*으로 제변환하는 것이다.

	cout << p1 << endl; // 진짜 주소가 나오게 위코드 수정

}
