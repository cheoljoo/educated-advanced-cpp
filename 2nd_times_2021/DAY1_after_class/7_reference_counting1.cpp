// reference_counting1
#include <iostream>
#include <vector>
class Car
{
	int speed;
public:
	~Car() { std::cout << "~Car" << std::endl; }
};

std::vector<Car*> v;

void foo()
{
	Car* p = new Car;

	v.push_back(p);

	// 여기서는 더이상 p가 필요 없습니다.
	// 메모리를 삭제해도 될까요 ?
	delete p; // 자원의 해지 시점을 정하기가 어렵다.!!
			  // 아무도 사용하지 않는 다는 보장이 있어야 한다.
}
int main()
{
	foo();
}
