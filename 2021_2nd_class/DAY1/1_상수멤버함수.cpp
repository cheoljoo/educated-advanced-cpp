#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	void print() const	        // 상수 member function
		// const 없으면 error.  서언부 구현부 모두에 적어야 한다. 
	{
		//x = 10;			// error. 상수 멤버 에서는 모든 멤버를 상수 취급

		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
	const Point pt(1, 2);
	// 상수 객체는 상수 member 함수만 호출할수 있다 *TT*
	// 실수를 할까봐 const를 붙이는게 아니라. 상수 객체로 선언을 해도 불러서 쓸수 있는 함수를 나타내기 위해서 이다. 

	//pt.x = 10;		    // error . pt는 상수 이므로 
	//pt.set(10, 20);	    // error.  상수 이므로 값을 바꿀수 없다. 
	pt.print();		
}


