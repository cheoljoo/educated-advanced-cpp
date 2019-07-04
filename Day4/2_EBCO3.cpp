/*
-  Empty일때만 상속으로 가게
- PAIR<int,Empty> 처리 되게
	- PAIR<int,Empty> p2;
	- PAIR<int,Empty> p2;으로 보내면 std::is_empty<T>::value가 false일 것이다.
*/

#include <iostream>
//using namespace std;

/*
- 
*/

class Empty {};

template<typename T , 
	typename U , 
	bool b = std::is_empty<T>::value >
struct PAIR;
//{ };
// 결국 위의 PAIR은 사용하지 않고 아래의 2개만 사용하게 됩니다.
// 이 경우는 선언만 해도 됩니다. 

// 아래 소스가 boost 라이브러리의 "compress_pair" 입니다. 
// c++ 표준인 unique_ptr을 만들때 이 기술이 사용됩니다. 

// ---------------------------
template<typename T, typename U> struct PAIR<T,U,false>
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

// T,U를 member로 가지는 것과 
// 상속 받아도 memory에는 (T ,U)가 들어간다.
// *this를 사용하면 T를 가리키게 된다. 
template<typename T, typename U> struct PAIR<T,U,true> : public T
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
	std::cout << sizeof(p) << std::endl;	// 4

	PAIR<int,Empty> p2;
	std::cout << sizeof(p2) << std::endl;	// 8  : 상속으로 쓰이지 않으니 8
}
