int x = 10;
int foo() { return x; }
int& goo() { return x; }

int main()
{
	int v1 = 10, v2 = 10;
	v1 = 20;
	10 = v1;
	v2 = v1;
	int* p1 = &v1;
	int* p2 = &10; 

	foo() = 20;
	goo() = 20;

	const int c = 10;
	c = 20; 
}









