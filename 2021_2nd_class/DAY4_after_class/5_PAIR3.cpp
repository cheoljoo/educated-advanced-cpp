// 5_PAIR2
#include <iostream>
#include <type_traits>
#include <string>

template<typename T, typename U> struct PAIR
{
	T first;
	U second;

	// std::decay_t<A> : A 에서, const, volatile, reference를 제거한 타입 꺼내기
	template<typename A, 
		     typename B,
			 typename = std::enable_if_t< std::is_same_v< std::decay_t<A>, T> && 
										  std::is_same_v< std::decay_t<B>, U> >>
	PAIR(A&& a, B&& b) : first(std::forward<A>(a)), second(std::forward<B>(b))
	{
	}

	PAIR() noexcept( std::is_nothrow_default_constructible_v<T> &&
				     std::is_nothrow_default_constructible_v<U> )
		: first(), second() {}
};

int main()
{
	std::string s1 = "AA";
	std::string s2 = "BBBB";

	PAIR<std::string, std::string> p1(s1, s2);	// 이 순간 T=string, A=string&

	PAIR<std::string, std::string> p2(s1, std::move(s2)); // T=string, A=string

	//PAIR<int*, int*> p3(1, 2);
}
/*
class AAA
{
	int n;
};
AAA a, b;
a = b; // ok

class BBB
{
	int& b; // 참조..1. 반드시 초기화 필요
	const int c;
public:
	BBB(int& x) : b(x) {}
};

int a, b;
BBB b1(a), b2(b);
b1 = b2; // ????
*/




