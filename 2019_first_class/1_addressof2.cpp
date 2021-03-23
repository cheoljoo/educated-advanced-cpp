// 1_addressof2.cpp  : 7 page
#include <iostream>
using namespace std;

class Point
{
	int x,y;
public:
	Point(){x=0;y=0;}
	// 내 조소를 알지 말라 기법 
	// 주소를 나타낼때는 0대신 nullptr을 사용하자 - c++11
	Point* operator&() const { return nullptr; }
};


// error가 없도록 수정해라.
int main()
{
	const Point pt;

	Point* p1 = reinterpret_cast<Point*>( &(reinterpret_cast<char&>(const_cast<Point&>(pt) )) );	// ok
		// char로 일반 변환해야 Point&로 먹지 않게 된다.  그래서 일단 char&으로 변환하여 다시 Point*으로 제변환하는 것이다.

	cout << p1 << endl; // 진짜 주소가 나오게 위코드 수정

}

