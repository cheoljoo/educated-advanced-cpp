#include <iostream>

// is_pointer 만들기

// is_pointer<T>::value : 컴파일 시간에 T가 포인터 인지 조사
//						  컴파일이 완료 되면 true/false로 결정됨.

// 1. primary template을 만들고 false 리턴( value = false )
template<typename T> struct is_pointer
{
	//bool value = false;   // 1. 변수이므로 컴파일 시간에 평가되지 않는다.
		    				// 2. c++11 이전에는 = 초기화 안됨.
	//enum { value = false }; // 그래서 enum 을 사용했었습니다

	static constexpr bool value = false; // C++11 부터는 이렇게 만드는 것이 좋습니다.
};

// 2. 조건을 만족하는 부분 특수화 버전을 만들고 true 리턴(value = true )
template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	// T : int, int*
	if ( is_pointer<T>::value ) 
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
