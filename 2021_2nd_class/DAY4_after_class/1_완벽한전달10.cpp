#include <iostream>
#include <functional> 

// ���̽�..   chronometry(f, *args, **kwargs):
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
		std::cout << "lvalue ��ü" << std::endl;
		return a + b;
	}
	int operator()(int a, int b) const &&
	{
		std::cout << "rvalue ��ü" << std::endl;
		return a + b;
	}
};

int main()
{
	Add add2;
	chronometry(add2, 1, 2); // lvalue �� () &
	chronometry(Add(), 1, 2);// rvalue �� () &&


//	Add add;
//	add(1, 2);
//	Add()(1, 2);
}




