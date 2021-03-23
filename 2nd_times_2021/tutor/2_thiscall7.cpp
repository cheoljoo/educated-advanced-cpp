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

	template<typename T, typename R, typename ... ARGS>
	ostream& operator<<(R(T::*f)(ARGS...))
	{
		printf("%p", f);
		return*this;
	}
};
ostream cout;

int main()
{
	int n = 0;
	double d = 0;

	cout << n << "\n";  // cout.operator<<(n)   int
	cout << d << "\n";  // double
	cout << &d << "\n"; // double* 가 없지만 void* 로 전달 가능
	cout << &main << "\n"; // 함수포인터 이지만 void* 로 전달 가능..
	cout << &Dialog::foo << "\n"; // 멤버 함수 포인터는 크기가 "8"일수도 있다.
								  // 그래서, void* 에 "멤버 함수 포인터"는 받을수 없다.

//	std::cout << &Dialog::foo << "\n";
}


