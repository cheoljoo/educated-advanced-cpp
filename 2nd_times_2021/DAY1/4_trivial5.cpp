#define _ENABLE_ATOMIC_ALIGNMENT_FIX
#include <iostream>
#include <thread>
#include <atomic>

struct Point
{
	int x;
	int y;
};

std::atomic<Point> pt;

int main()
{
	Point p = pt.load();

	std::cout << pt.is_lock_free() << std::endl;
}
