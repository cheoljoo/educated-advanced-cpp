// 6_enable_if1.cpp
// C++11 표준에 이미 enable_if 가 있습니다.
template<bool, typename T = void > struct enable_if
{
	using type = T; //typedef  T type;
};
// 부분 특수화시에 "디폴트 값"은 표기하면 안됩니다
// 표기하지 않아도, primary 의 디폴트값이 사용됩니다.
template<typename T> struct enable_if<false, T> 
{
	// 핵심. 1번째 인자가 false 인경우에는 "type" 이 없습니다.
};

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2, 그런데, void 변수는 만들수 없으므로	
									//          error. 
	enable_if<false, int>::type n3; // "::type" 이 없으므로 에러.
	enable_if<false>::type      n4; // "::type" 이 없다.
}

// enable_if<false, 타입>::type	==> ::type 없음
// enable_if<false>::type       ==> ::type 없음   

// enable_if<true, 타입>::type	==> 타입
// enable_if<true>::type        ==> void




