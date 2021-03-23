#include <iostream>
// 핵심 1. 멤버 함수 호출시 객체의 주소가 같이 전달(ecx, rcx 레지스터)된다.
//         ==> "this call" 이라는 용어를 사용합니다
// 2. static 멤버 함수는 this가 전달되지 않는다.(this call) 아님.

class Point
{
	int x, y;
public:
	void set(int a, int b) // set(Point* this, int a, int b)
	{						
		x = a;			   // this->x = a	 
		y = b;			   // this->y = b
	}		
	static void foo(int a) // foo(int a)
	{
		x = a;				// this->x = a로 변경해야 하는데...
							// 문제는 this가 없다!!
						// 그래서 static 멤버 함수에서는 멤버 데이타 접근 안됨
	}
};
int main()
{
	Point::foo(10); // push 10
					// call Point::foo

	Point p1, p2;

	p1.set(10, 20); // set( &p1, 10, 20 )
	p2.set(10, 20); // set( &p2, 10, 20 )
					// 32bit 에서는
					// push 20
					// push 10  ===> 실제 인자는 스택으로
					// mov  ecx, &p2 객체는 레지스터에 담아서
					//				 64bit 는 rcx 레지스터
					// call Point::set

	// g++ 2_thiscall1.cpp  -S    => 소스.s  
	// cl  2_thiscall1.cpp  /FAs  => 소스.asm
}









