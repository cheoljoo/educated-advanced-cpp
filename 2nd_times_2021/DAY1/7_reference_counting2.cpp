#include <iostream>
#include <vector>

class Car
{
	int refCount = 0;
	int speed;
public:
	void AddRef() { ++refCount; }

	void Release() { if (--refCount == 0) delete this; }

protected:
	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
    Car c;

	Car* p1 = new Car;
	Car* p2 = p1;
}
