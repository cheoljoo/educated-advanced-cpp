#include <iostream>

// 멤버 변수 포인터
struct Point
{
	int x{ 0 };
	int y{ 0 };
};

templte <typename T> T Max(T a , T b)
{
	return a < b ? b : a ;
}
int main()
{
	Point p1, p2;
	Max(p1,p2);

}
