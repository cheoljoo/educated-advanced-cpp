int main()
{
	int n = 10;

	// lvalue 와 rvalue를 모두 받을수 있는 foo 함수를 만들고 싶다
	foo(n);
	foo(10);
}
