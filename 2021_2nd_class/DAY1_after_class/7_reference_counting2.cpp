#include <iostream>
#include <vector>

class Car
{
	int refCount = 0;
	int speed;
public:
	void AddRef() { ++refCount; }

	void Release() { if (--refCount == 0) delete this; }

	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef();    // 규칙 1. 객체 생성시 카운트 증가
	Car* p2 = p1;
	p2->AddRef();    // 2. 객체의 주소 복사시 카운트 증가

	p2->Release();   // 3. 객체 사용후 참조계수 감소
	std::cout << "-------------------" << std::endl;
	p1->Release();   // 이순간 카운트가 0되므로 객체 파괴
}




