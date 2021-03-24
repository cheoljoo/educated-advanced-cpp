#include <thread>
#include <memory>
#include <iostream>

/*
void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << " bytes" << std::endl;
}
*/
class Point
{
	int x, y;
public:
	Point(int a, int b) {  }
};

int main()
{
	// 아래 코드는 동적 메모리 할당이 몇번 발생할까요 ?
	std::shared_ptr<Point> sp(new Point(1, 2));
}







