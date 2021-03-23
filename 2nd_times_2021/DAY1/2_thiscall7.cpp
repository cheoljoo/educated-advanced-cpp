#include <iostream>

class Dialog
{
public:
	void foo() {}
};

class ostream
{
public:
	ostream& operator<<(const char* a) { printf("%s", a); return *this; }
	ostream& operator<<(void*	 a)    { printf("void*  : %p", a); return *this; }
	ostream& operator<<(int		 a)    { printf("int    : %d", a); return *this; }
	ostream& operator<<(double   a)    { printf("double : %f", a); return *this; }
	ostream& operator<<(bool     a)    { printf("bool   : %d", a); return *this; }
};
ostream cout;

int main()
{
	int n = 0;
	double d = 0;

	cout << n << "\n";
	cout << d << "\n";;
	cout << &d << "\n";;
	cout << &main << "\n";;
	cout << &Dialog::foo << "\n";
}


