#include <initializer_list>

void foo(std::initializer_list<int> e)
{
	auto p = e.begin(); // ���� �ݺ���
}
int main()
{
	// e : ������ �ϳ��� ���� ����
	std::initializer_list<int> e = { 1,2,3,4,5 };


	foo(e);
	foo({ 1,2,3 });
	foo({ 1,2,3,4,5 });
	foo({ 1,2,3,4,5,6,7,8 });

}