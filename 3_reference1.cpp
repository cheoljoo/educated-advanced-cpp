// 3_참조계수1.cpp
// delete를 할 시점을 잡는게 힘들다. 
//
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Car
{
public:
	~Car() { cout << "~Car" << endl; }
};
vector<Car*> v;

void foo()
{
	Car* p = new Car;
	v.push_back(p);
	// 더이상 P가 필요없습니다. delete해도 될까요?
	delete p;

}
int main()
{
	foo();
}
