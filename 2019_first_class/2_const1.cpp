// 2_const1.cpp  : 상수 멤버 함수 
// 앞으로 const 붙이는 것을 꼭 해주세요.. 무지 중요합니다.
#include <stdio.h>
#include <iostream>
using namespace std;

class Rect
{
	int x=0,y=0,w=10,h=10; // from c++11
public:
	int getArea() const		// 상수 멤버 함수 : 이 안에서 값을 변경하면 에러
	{
		return w*h;
	}
	//void setX(int a){ x = a; }
};

int main()
{
	const Rect r; // 생성자로 초기화 했다고 가정
		//  상수 객체
		//  ** 상수 객체는 member 함수를 부를수없다. 그러나, 함수 뒤에 const를 한 것을 부를수 있다.
		//  int getArea()뒤에 const가 없으면 에러가 된다.   header에는 꼭 const를 붙여주어야 한다.
	//r.setX(100);

	int n= r.getArea();
		// 핵심 : 상수 객체는 상수 함수만 호출 가능하다.
		//   "객체의 상태를 변경하지 않는 
		//   모든 멤버 함수(getter)는 반드시 
		//   상수 멤버 함수되어야 한다."
}
