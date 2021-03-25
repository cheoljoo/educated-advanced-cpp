// 10_EBCO -  73 page
#include <iostream>

// Empty Class : non static 멤버 데이타가 없는 클래스
//					크기가 1이다.
class Empty 
{
	static int cnt;
public:
	void foo() {}
};
int Empty::cnt = 0;

struct Plus
{
	int operator()(int a, int b) { return a + b; }
};

int main()
{
	Empty e;
	std::cout << sizeof(e) << std::endl; // 1
}





