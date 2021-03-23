#include <iostream>
#include <type_traits>

template<typename T> class Point
{
	T x;
	T y;
public:
	Point(T a, T b) : x(a), y(b) {}




	// ������ �����Ҷ��� �����ڸ� ����� �ʹ�.
	// ��� : 1) enable_if �� ����ؼ� ������ ǥ���ؾ� �Ѵ�.
	//        2) enable_if �� �ᱹ ������ �����ϸ� "::type" �� �ְ�, �������� ������ ����

	// enable_if �� ��ġ : ��ȯ Ÿ��, �Լ� ���� Ÿ��, ���ø� ����
	//					   �����ڴ� ��ȯ Ÿ���� ����!!!

	// �Լ� ���� ��ġ�� ���� : ������ ���� ���ڰ� �����ϰ� ǥ���ȴ�.
	//					       �ڵ尡 ������ ������ �� ������.
	/*
	template<typename U>
	Point(const Point<U>& pt, 
		  typename std::enable_if< ����, int>::type = 0 ) : x(pt.x), y(pt.y) 
	{
	}
	*/
	// ���ø����ڿ� enable_if�� �����ϸ� �Լ��� ��� ��ü�� ���� ��������.
	/*
	template<typename U, 
	         typename std::enable_if<std::is_convertible_v<U,T>, int>::type = 0> // int = 0>
	Point(const Point<U>& pt) : x(pt.x), y(pt.y)
	{
	}
	*/
	/*
	// �Ʒ� ó���� ����
	template<typename U,
			 typename  = typename std::enable_if<����, int>::type >
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


// c++17 :  std::vector v = {1,2,3}   // v<int> ���� <> ��� �˴ϴ�.
