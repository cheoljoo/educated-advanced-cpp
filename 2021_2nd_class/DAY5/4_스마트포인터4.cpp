#include <iostream>
// C++11의 스마트포인터를 사용하려면 필요한 헤더
#include <memory>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// 핵심 1. 
	std::shared_ptr<int> p1(new int);  
	std::shared_ptr<int> p2 = new int; 

	// 핵심 2. 스마트 포인터의 크기
	std::cout << sizeof(p3)   << std::endl; // ?
	std::cout << sizeof(int*) << std::endl; // ?

	// 핵심 3. -> 와 . 연산자
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

}



