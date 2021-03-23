// 아래 코드는 컴파일 하면 에러가 있을까요 ?
template<typename T> void foo(T a)
{
//	if (false)
//		*a = 10;

	// C++17 의 새로운 if 문
	// 컴파일 시간 if
	// 컴파일 시간에 조건을 조사해서. 거짓이 되면
	// "템플릿 ==> C++코드" 로 생성을 안함(인스턴스화 안됨)
	// g++ : -std:c++17
	// vc  : /std:c++latest
	if constexpr (false)
		*a = 10;
}

int main()
{
	foo(10);
}