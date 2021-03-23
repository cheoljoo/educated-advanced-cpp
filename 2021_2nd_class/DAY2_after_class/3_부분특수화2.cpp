#include <iostream>
using namespace std;

// primary template
template<typename T, typename U> struct Object
{
	static void foo() { cout << "T, U" << endl; }
};

template<typename T, typename U> struct Object<T*, U*>
{
	static void foo() { cout << "T*, U*" << endl; }
};
template<typename T, typename U> struct Object<T*, U>
{
	static void foo() { cout << "T*, U" << endl; }
};

// 부분 특수화의 핵심!!
// primary template 의 템플릿 인자가 2개 일때
// 1. 사용자는 반드시 2개 전달해야 한다. : Object<int, int>
// 2. 부분 특수화 오른쪽 끝에도 반드시 2개 표기 : 
// 3. 하지만 템플릿 인자의 갯수는 변경될수 있다.
template<typename T> struct Object<T, T>   // <<===== 이 부분이 2개
{
	static void foo() { cout << "T, T" << endl; }
};
template<typename U> struct Object<int, U>   
{
	static void foo() { cout << "int, U" << endl; }
};

// specialization(특수화) - 가장 우선순위가 높다.
template<> struct Object<int, short>
{
	static void foo() { cout << "int, short" << endl; }
};

// primary template 의 템플릿 인자는 2개지만
// 부분 특수화 시에는 아래처럼 3개가 될수도 있습니다.
template<typename A, typename B, typename C> struct Object<A, Object<B, C> >
{
	static void foo() { cout << "A, Object<B, C>" << endl; }
};

int main()
{
	Object<int, double>::foo();	// T,  U
	Object<int*, double*>::foo();  // T*, U*
	Object<int*, double>::foo(); // T*, U
//	Object<int, int>::foo();     // T, T   errro
								 // <T,T> 와 <int, U> 에 모두 가능해 집니다.

	Object<int, char>::foo();    // int, U  
	
	Object<int, short>::foo();   // int, short

	Object<short, Object<char, double>>::foo(); // "A, Object<B, C>"  라고 출력해보세요.
}
