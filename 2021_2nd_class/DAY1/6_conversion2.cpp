class Test
{
	int value;
public:
	Test(int n) : value(n) {}
};

int main()
{
	// 아래 2줄의 차이점은 ?
	Test t1(5);  	
	Test t2 = 5; 
}
