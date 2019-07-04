/*
- concept1  : C++20에 추가되는 문법
	- 에러 메시지가 명확히 나오게 하는 목적으로 쓴다.
- 모든 concept 은 bool이다.
bool concept LessThanComparable(T a,T b)
안되면 위처럼 bool 추가

compile check

*/

#include <iostream>
//using namespace std;

/*
- 
*/

// 혹시 < 연산이 불가능한 것을 사용하면
// error msg로 LessThanComparable이 지원하지 않는다고 나옵니다. 

// 1. concept을 만듭니다.
template<typename T>
concept LessThanComparable(T a,T b)
{
	{a < b} -> bool;
}

// 2. 템플릿을 만들때 T가 가져야 하는 조건(개념)을 명시 합니다. 
template<typename T> requires LessTanComparable 
T Max(T a, T b)
{
	return b < a ? a : b;
}

// 아래 처럼 축약해서 사용 가능하니다 
LessThanComparable 
Max(LessThanComparable a, LessThanComparable b)
{
	return b < a ? a : b;
}

int main()
{
	//std::cout << Max(1,2) << std::endl;
	Max(1,2);
}


template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
foo(T p){}
template<typename T>
typename std::enable_if<!std::is_pointer<T>::value>::type
foo(T p){}

// 이렇게 간단하게 쓸수 있다. concept
// g++ -fconcepts
void foo(PointeConcept) {}
void foo(NoPointeConcept) {}
void goo(std::DefaultConstructible a)
{
	using T = DefaultConstructible;
	T b; 	// 디폴트 생성자 필요
}
// cppreference.com  : https://en.cppreference.com/w/cpp/concepts

