#include <iostream>
#include <type_traits>

template<typename T> class Point
{
	T x;
	T y;
public:
	Point(T a, T b) : x(a), y(b) {}




	// 조건을 만족할때만 생성자를 만들고 싶다.
	// 방법 : 1) enable_if 를 사용해서 조건을 표기해야 한다.
	//        2) enable_if 는 결국 조건을 만족하면 "::type" 이 있고, 만족하지 않으면 없다

	// enable_if 의 위치 : 반환 타입, 함수 인자 타입, 템플릿 인자
	//					   생성자는 반환 타입이 없다!!!

	// 함수 인자 위치에 적용 : 사용되지 않은 인자가 복잡하게 표현된다.
	//					       코드가 복잡해 보여서 잘 사용안함.
	/*
	template<typename U>
	Point(const Point<U>& pt, 
		  typename std::enable_if< 조건, int>::type = 0 ) : x(pt.x), y(pt.y) 
	{
	}
	*/
	// 템플릿인자에 enable_if를 적용하면 함수의 모양 자체는 보기 좋아진다.
	/*
	template<typename U, 
	         typename std::enable_if<std::is_convertible_v<U,T>, int>::type = 0> // int = 0>
	Point(const Point<U>& pt) : x(pt.x), y(pt.y)
	{
	}
	*/
	/*
	// 아래 처럼도 가능
	template<typename U,
			 typename  = typename std::enable_if<조건, int>::type >
		Point(const Point<U>& pt) : x(pt.x), y(pt.y)
	{
	}
	*/

	template<typename U,
		    std::enable_if_t<std::is_convertible_v<U, T> >* = nullptr > 
		Point(const Point<U>& pt) : x(pt.x), y(pt.y)
	{
	}


	template<typename> friend class Point;
};



//template<void* n = 0> class Test {};
template<void* n = nullptr> class Test {};



int main()
{
	Test<> t;

	Point<double> p1(2.1, 3.4);
	Point<int> p2(1, 2);

	Point<double> p3 = p1;
	Point<double> p4 = p2;

//	Point<int*> p5 = p1; // 
}


// c++17 :  std::vector v = {1,2,3}   // v<int> 에서 <> 없어도 됩니다.
