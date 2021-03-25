#include <iostream>

class Test
{
public:
	Test(int a) {}

	void resize() {}
};
// "Member Detect" 라는 C++ IDioms 입니다.
// C++20 부터는 "Concept"을 사용하면 아주 간단해집니다.
/*
template<typename T> 
concept has_resize = requires(T a)
{
	{ a.resize() };
};
int main()
{
	// concept이름<타입> 의 최종 결과는 bool 입니다.
	bool b = has_resize<Test>;
}
*/

using YES = int[2];
using NO  = int[1];

template<typename T> YES&  check(decltype(std::declval<T>().resize())* p);
template<typename T> NO&   check(...);

template<typename T> struct has_resize_function
{
	static constexpr bool value = (sizeof(check<T>(0)) == sizeof(YES));
};

int main()
{
	bool b = has_resize_function<Test>::value;

	std::cout << b << std::endl;
}



