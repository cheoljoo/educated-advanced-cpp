// integral_constant1.cpp
// traits7번 복사해오세요. - 주석 제거
#include <iostream>
#include <type_traits>

// 포인터와 포인터가 아닌 경우를 별도의 함수 템플릿으로 분리
template<typename T> void pointer(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void not_pointer(const T& v)
{
	std::cout << v << std::endl;
}

template<typename T> void printv(const T& v)
{
	// 아래 코드는 if( false ) 라도 pointer 템플릿을 실제 함수로 인스턴스화 하게 됩니다.
	if (std::is_pointer_v<T>)
		pointer(v);
	else
		not_pointer(v);		
}
int main()
{
	int n = 10;
	printv(n); 
}

