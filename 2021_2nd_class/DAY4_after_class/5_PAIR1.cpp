// 핵심 : forwarding reference가 아닌것에 주의 하라!!
template<typename T> class Test
{
public:
	// 아래 함수는 함수 템플릿이 아니라, 클래스 템플릿의 일반 멤버 함수 입니다.
	void foo(T&& arg) {}

	// forwarding reference 가 되려면 함수 템플릿이 되어야 합니다.
	template<typename U> void goo(U&& arg) {}
};

int main()
{
	int n = 0;

	Test<int> t; // 이 순간 T=int로 결정됩니다.
				 // void foo(int&& arg) 로 결정되었습니다.

	// 다음 코드가 에러가 있을지 생각해 보세요
	t.foo(10); // ok
	t.foo(n);  // error

	t.goo(10); // ok
	t.goo(n);  // ok
}