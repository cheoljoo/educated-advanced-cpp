#include <iostream>
#include <type_traits>

template<typename T, typename U> struct PAIR
{
	T first;
	U second;

	PAIR(const T& a, const U& b) : first(a), second(b) {}
};

