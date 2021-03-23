#include <iostream>
#include <vector>

class Car
{
	int refCount = 0;
	int speed;
public:
	void AddRef() { ++refCount; }

	void Release() { if (--refCount == 0) delete this; }

	// protected 소멸자 : 객체를 스택에 만들수 없게 할때 사용
protected:
	~Car() { std::cout << "~Car" << std::endl; }

	// 힙에 만들수 없고, 스택만 가능하게 하려면
	// void* operator new(std::size_t sz) { return nullptr; } // C++ Idioms 71번기술
};

int main()
{
//	Car c; // 스택 객체. 파괴시 소멸자를 호출해야 하는데
			// 소멸자가 protected에 있다.

	Car* p1 = new Car;
	p1->AddRef();  
	Car* p2 = p1;
	p2->AddRef();  

	p2->Release(); 
	std::cout << "-------------------" << std::endl;
	p1->Release(); 
}




