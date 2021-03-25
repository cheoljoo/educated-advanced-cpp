#include <iostream>
#include <functional> 

// ÆÄÀÌ½ã..   chronometry(f, *args, **kwargs):
//					f(*args, **kwargs)
template<typename F, typename ... Ts>
decltype(auto) chronometry(F&& f, Ts&& ... args)
{
	return std::invoke( std::forward<F>(f), std::forward<Ts>(args)...);
}

struct Add
{
	int operator()(int a, int b) const &
	{
		std::cout << "lvalue °´Ã¼" << std::endl;
		return a + b;
	}
	int operator()(int a, int b) const &&
	{
		std::cout << "rvalue °´Ã¼" << std::endl;
		return a + b;
	}
};

int main()
{
	Add add2;
	chronometry(add2, 1, 2); // lvalue ÀÇ () &
	chronometry(Add(), 1, 2);// rvalue ÀÇ () &&


//	Add add;
//	add(1, 2);
//	Add()(1, 2);
}




