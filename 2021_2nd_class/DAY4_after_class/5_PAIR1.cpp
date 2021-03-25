// �ٽ� : forwarding reference�� �ƴѰͿ� ���� �϶�!!
template<typename T> class Test
{
public:
	// �Ʒ� �Լ��� �Լ� ���ø��� �ƴ϶�, Ŭ���� ���ø��� �Ϲ� ��� �Լ� �Դϴ�.
	void foo(T&& arg) {}

	// forwarding reference �� �Ƿ��� �Լ� ���ø��� �Ǿ�� �մϴ�.
	template<typename U> void goo(U&& arg) {}
};

int main()
{
	int n = 0;

	Test<int> t; // �� ���� T=int�� �����˴ϴ�.
				 // void foo(int&& arg) �� �����Ǿ����ϴ�.

	// ���� �ڵ尡 ������ ������ ������ ������
	t.foo(10); // ok
	t.foo(n);  // error

	t.goo(10); // ok
	t.goo(n);  // ok
}