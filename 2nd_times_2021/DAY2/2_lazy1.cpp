// 아래 코드는 왜 에러일까요 ?
class A
{
	int data;
public:
	void foo() { *data = 10; } 
};
int main()
{
	A a;
}
