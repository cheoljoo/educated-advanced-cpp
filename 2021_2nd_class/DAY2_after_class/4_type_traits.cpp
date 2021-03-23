#include <iostream>

// type traits  : 타입(T) 의 다양한 특성(traits, 특질)을 조사하는 기술

template<typename T> void printv(const T& v)
{
	if ( T is pointer type )
		std::cout << v << " : " << *v << std::endl;
	else 
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

