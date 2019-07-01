// 3_참조계수2.cpp
// delete를 할 시점을 잡는게 힘들다. 
//
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Car
{
	int m_refCount = 0 ; // 참조계수를 위한 변수
		// c++11부터 member field 초기화 가능
public: 
	void ref() { ++m_refCount; }
	void deref(){ if(--m_refCount == 0) delete this; }

	// Protectoed 소멸자 : 객체를 스택에 만들수 없게 한다.
	//      195 page 아래쪽 코드 : 객체를 heap에만 만들게 하거나 , stack에 못만들게 하는 방법
	//  Car c; 와 같이 stack에서 부를때는 , 함수를 빠져나갈때 소멸자를 부르지만, call되지 않아서 에러가 발생한다.
protected :
	~Car() { cout << "~Car" << endl; }
};
vector<Car*> v;

int main()
{
	Car* p1 = new Car;
	p1->ref(); 	// 규칙 1 . 객체 생성시 참조 계수 증가

	Car* p2 = p1;
	p2->ref(); 	// 규칙 2 . 포인터 복사시 참조계수 증가

	p2->deref(); 	// 규칙 3 . 더이상 필요없을때 참조계수 감소
	p1->deref(); 	// 규칙 3 . 더이상 필요없을때 참조계수 감소


	Car c; 		// error : 위와 같이 protected일때 에러
}
