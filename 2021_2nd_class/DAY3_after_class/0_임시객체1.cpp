
// cafe.naver.com/cppmaster 게시판에서   DAY3.zip  받으시면 됩니다.
// 오늘 "modern C++" 의 핵심 기술들.

// 0_임시객체1
#include <iostream>
#include <type_traits>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
//	Point pt(1, 2); // named object
//	Point(1, 2);    // unnamed object , temporary
					// 수명 : 문장의 끝..

	Point(1, 2), std::cout << "X" << std::endl;

	std::cout << "-------" << std::endl;
}





