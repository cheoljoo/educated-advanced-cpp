#include <initializer_list>

void foo(std::initializer_list<int> e)
{
	auto p = e.begin(); // 시작 반복자
}
int main()
{
	// e : 포인터 하나와 갯수 관리
	std::initializer_list<int> e = { 1,2,3,4,5 };


	foo(e);
	foo({ 1,2,3 });
	foo({ 1,2,3,4,5 });
	foo({ 1,2,3,4,5,6,7,8 });

}