#include <iostream>

// C++11 에서는 int2type을 발전시킨 아래 템플릿을 제공합니다.
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};
// 아래 3줄은 모두 다른 타입
//integral_constant<int, 0> n0;
//integral_constant<int, 1> n1;
//integral_constant<short, 0> s0;

// 아래 2줄이 중요합니다.
// true/false           : 참/거짓을 나타내는 값, 같은 타입
// true_type/false_type : 참/거짓을 나타내는 타입, 다른 타입
using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// 실제 is_pointer는 아래처럼 만들게 됩니다.
template<typename T> struct is_pointer     : false_type {}; // value = false
template<typename T> struct is_pointer<T*> : true_type  {}; // value = true


int main()
{

}

