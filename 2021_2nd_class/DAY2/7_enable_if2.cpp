#include <iostream>
#include <type_traits>


template<typename T> T gcd(T a, T b)
{
	return 0;
}
int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);
}
