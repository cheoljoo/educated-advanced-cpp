#include <iostream>
#include <memory>

/*
void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}
*/
struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	// �Ʒ� �ڵ�� ���� �޸� �Ҵ��� ����ϰ� �ɱ�� ?
	std::shared_ptr<Point> sp(new Point(1, 2));
	
	
}

void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

