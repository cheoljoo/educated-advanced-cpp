#include <iostream>
#include <type_traits>

template<typename T> class Point
{
	T x;
	T y;
public:
	Point(T a, T b) : x(a), y(b) {}

	// U가 T 로 암시적 변환이 가능한 경우만 "복사 생성자를 만들게 하는 것이 좋습니다."
	// 핵심 : 생성자는 리턴 타입이 없기 때문에 enable_if 를 리턴 타입자리에 놓을수 없습니다.
	//        이럴때는 대부분 "템플릿 인자"를 활용 합니다.
	/*
	template<typename U>
	std::enable_if_t< std::is_convertible_v<U, T> > // error. 생성자는 리턴 타입이 없다.
	Point(const Point<U>& pt) : x(pt.x), y(pt.y) {}
	*/
	template<typename U,
			 typename V = std::enable_if_t< std::is_convertible_v<U, T> > >	
						// std::enable_if< std::is_convertible_v<U, T> >::type >	
	Point(const Point<U>& pt) : x(pt.x), y(pt.y) {}


	template<typename> friend class Point;
};


int main()
{
	Point<double> p1(2.1, 3.4);
	Point<int> p2(1, 2);

	Point<double> p3 = p1;
	Point<double> p4 = p2;

	Point<int*> p5 = p1; // 
}

