/* 12_member_detect4 143 page
- 
*/

#include <iostream>
#include <type_traits>
#include <vector>
#include <array>
#include <complex>

template<typename T> struct has_front_function
{
    typedef char YES[1];        // 143 page ArrayOne
    typedef char NO[2];

    // T() : T 타입의 객체 생성
    // decltype(표현식) arg : 표현식의 타입과 동일한 타입의 변수 arg from C++11
    template<typename U> static YES& test( decltype( std::declval<U>().front())* arg );
    template<typename U> static NO& test(...){}

    static constexpr bool value = (sizeof(test<T>(0)) == sizeof(YES));
};

int main()
{
	bool b = has_front_function<std::vector<int>>::value;
	//bool b = has_front_function<std::complex<double>>::value;

	std::cout << b << std::endl;
}


// cppreference.com  allocator 검색
