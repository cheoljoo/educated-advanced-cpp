// 6_enable_if1.cpp

template<bool, typename T = void > struct enable_if
{
	typedef  T type;
};

template<typename T> struct enable_if<false, T> 
{
};

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; 
	enable_if<true>::type       n2; 
	enable_if<false, int>::type n3; 
}
