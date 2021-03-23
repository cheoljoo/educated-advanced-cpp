#include <iostream>
#include <type_traits>	

template<typename T> void printv(const T& v)
{
	// T 의 포인터여부에 따라 다른 알고리즘 만들기
	// 방법 1. ::value, _v 조사
	if ( std::is_pointer_v<T> )
	{
		// 단, *v 같은 표기법은 안됨
	}
	else
	{
	}

	// *v 같은 표기법이 필요 하면
	// 방법 2. if constexpr - C++17
	// 방법 3. true_type/false_type에의한 함수 오버로딩
	printv_imp(v, std::is_pointer<T>() );
}
template<typename T> void printv_imp(const T& a, std::true_type)  {} // *v 사용가능
template<typename T> void printv_imp(const T& a, std::false_type) {}



int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}



// 오후는 13:00 부터 진행합니다.