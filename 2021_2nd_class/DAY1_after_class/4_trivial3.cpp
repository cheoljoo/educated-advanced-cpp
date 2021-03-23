#include <iostream>

struct Point
{
	int x, y;
	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

	// 사용자가 복사 생성자를 직접 제공하면 구현에 상관없이 "trivial" 하지 않습니다.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

// 왜 trivial 여부를 조사하는가 ?
// 템플릿 작성시 "trivial" 여부에 따라 "최적화된 알고리즘" 구현
/*
template<typename T> 
void copy(T* dst, T* src, std::size_t sz)
{
	if ( std::is_trivially_copyable_v<T> )
	{
		std::cout << "버퍼를 통째로 복사" << std::endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		std::cout << "요소를 한개씩 복사 생성자로 복사" << std::endl;
		while (sz--)
		{
			new(dst) T(*src); // 복사 생성자 호출 모양 - "placement new 수업"
			++dst, ++src;
		}
	}
}
*/

template<typename T>
void copy(T* dst, T* src, std::size_t sz)
{
	// if constexpr  : c++17 
	//					"템플릿 ==> C++ 함수" 를 생성할때
	//					조건을 만족하지 않은 코드는 
	//				    C++ 코드 자체를 생성하지 않음.. 
	if constexpr (std::is_trivially_copyable_v<T>)
	{
		std::cout << "버퍼를 통째로 복사" << std::endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		std::cout << "요소를 한개씩 복사 생성자로 복사" << std::endl;
		while (sz--)
		{
			new(dst) T(*src); // 복사 생성자 호출 모양 - "placement new 수업"
			++dst, ++src;
		}
	}
}


int main()
{
	Point pt1[5] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	Point pt2[5];

	copy(pt2, pt1, 5);

}
