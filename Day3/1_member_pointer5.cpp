/* 1_member_pointer5
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

class Dialog
{
public:
	int color;
	void Close() {}
};
void foo() {}


/*
int main()
{
	int n = 0;

	void* p1 = &n;	// ok
	void* p2 = &foo;	// ok
	// void* p3 = &Dialog::color; 	// error becasue of offset
	// void* p4 = &Dialog::Close; 	// error

}
*/

void goo(void* p){ printf("void %p\n",p); }
void goo(bool b){ printf("bool %d\n",b); }
int main()
{
	int n = 0;
	goo(&n);
	goo(&foo);
	goo(&Dialog::color);
	// printf로 찍으면 0 인데 , cout이나 if로 볼때는 1로 나온다. 
	printf("%d\n",&Dialog::color);
	if( &Dialog::color) std::cout << "true" << std::endl;
	goo(&Dialog::Close);

	std::cout << &n << std::endl; 	// cout.operator<<(void*)
	std::cout << &Dialog::Close  << std::endl;	// cout.operator<<(bool)
}
