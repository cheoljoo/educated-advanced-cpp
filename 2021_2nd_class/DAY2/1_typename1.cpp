class Test
{
public:
	enum { value = 1 };
	typedef int DWORD;
};
int p = 0;

template<typename T> void foo(T a)
{
	// 아래 2줄에서 * 의 의미를 생각해 보세요(1. 곱하기, 2. 포인터 변수 선언)
	Test::value * p;
	Test::DWORD * p;
}
int main()
{
	Test t;
	foo(t);
}
