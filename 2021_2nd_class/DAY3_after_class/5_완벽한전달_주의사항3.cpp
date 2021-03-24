// 9_완벽한전달_주의사항3

// forwarding reference 이야기

template<typename T> class Test
{
public:
	void foo(T&& arg)
	{
	}
};
int main()
{
	int n = 0;
	Test<int> t; 

	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n); 
	t.foo(10); 

}
