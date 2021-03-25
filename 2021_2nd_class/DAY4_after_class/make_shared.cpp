#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {  }
};

int main()
{
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);

	// make_shared �� ��ǥ���� 2���� ����
	// 1. �޸��� ȿ����( ��ü + ������ü�� �ѹ��� �Ҵ�)
	// 2. ���� ������
	// �ڿ��� �Ҵ��, �ڿ� ������ü�� ������ �ݵ�� �ѹ��� �̷������ �����ϴ�.
	// foo( std::shared_ptr<Point>(new Point(1, 2)), goo() );

	// std::make_shared<Point>(1, 2) : Point ��ü ������ shared_ptr ������ 
	//								�ϳ��� �Լ��� ó��.

	foo(std::make_shared<Point>(1, 2), goo());

	// RAII : Resource Acquision Is Initialization
	//     �ڿ��� ȹ���� "�ڿ�������ü��" �ʱ�ȭ �ɶ� �̴�.
}

void foo(std::shared_ptr<Point> sp, int a ) {}

int goo() { return 0; }






// ���� ������ 13:00 ���� �����մϴ�.

