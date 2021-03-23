// 6_enable_if5 - git 에 4_trivial3.cpp 복사해오세요.. 주석 지우세요
#include <iostream>

struct Point
{
	int x, y;
	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

//	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

// github.com/aosp-mirror   안드로이드 소스

// platform_system_core  레포지토리 검색

// libutils/include/utils/typehelpers.h 파일에서 copy_type 함수 찾아서 모양 보세요

template<typename T>
std::enable_if_t< std::is_trivially_copyable_v<T>>
copy(T* dst, T* src, std::size_t sz)
{
	std::cout << "버퍼를 통째로 복사" << std::endl;
	memcpy(dst, src, sizeof(T)*sz);
}

template<typename T>
std::enable_if_t< !std::is_trivially_copyable_v<T>>
copy(T* dst, T* src, std::size_t sz)
{
	std::cout << "요소를 한개씩 복사 생성자로 복사" << std::endl;
	while (sz--)
	{
		new(dst) T(*src); // 복사 생성자 호출 모양 - "placement new 수업"
		++dst, ++src;
	}
}


int main()
{
	Point pt1[5] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	Point pt2[5];

	copy(pt2, pt1, 5);

}