/*
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

class Empty {};

/*
template<typename T, typename U> struct PAIR
{
	T v1;
	U v2;
	T& getValue1() { return v1; }
	U& getValue2() { return v2; }

	template<typename A , typename B>
	PAIR(A&& a, B&& b)
		: v1(std::forward<A>(a))
		, v2(std::forward<B>(b)){}

	PAIR() = default;
};
*/

// T,U를 member로 가지는 것과 
// 상속 받아도 memory에는 (T ,U)가 들어간다.
// *this를 사용하면 T를 가리키게 된다. 
template<typename T, typename U> struct PAIR : public T
{
	U v2;
	T& getValue1() { return *this; }
	U& getValue2() { return v2; }

	template<typename A , typename B>
	PAIR(A&& a, B&& b)
		: T(std::forward<A>(a)) 	// 기반 클래스 생성자 호출
		, v2(std::forward<B>(b)){}

	PAIR() = default;
};

int main()
{
	PAIR<Empty,int> p;
	std::cout << sizeof(p) << std::endl;	// 8->4
}
