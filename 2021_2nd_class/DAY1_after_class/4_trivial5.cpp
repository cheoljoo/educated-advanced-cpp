#define _ENABLE_ATOMIC_ALIGNMENT_FIX
#include <iostream>
#include <thread>
#include <atomic>

struct Point
{
	int x;
	int y;
	int z;
	Point() {}
	Point(const Point& pt) {} // 사용자가 만든 복사 생성자
};

// 핵심 : sizeof(Point) 를 생각해 보세요..
// 크기가 64bit 이하인 타입 => lock free 로 동작(CPU 명령으로)
std::atomic<Point> pt; //  atomic<타입> 에서 "타입은 반드시 복사 생성자가 
						// trivial 해야 합니다.

int main()
{
	Point p = pt.load(); // pt가 64bit 이면 lock free(CPU 명령)
						 // 64이상이면 "spin lock" 으로 구현.	
						// 복사 생성자가 trivial 하지 않으면 

	std::cout << pt.is_lock_free() << std::endl;
}


