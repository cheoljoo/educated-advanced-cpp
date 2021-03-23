/*
- 
*/

//#include <iostream>
//using namespace std;

/*
- 함수 객체의 장점 2.
	- 다른 함수의 인자로 전달되는 함수를 만들때
	1. 일반함수를 보내면 다시 호출시 인라인 치환되지 못한다.
	1. 함수 객체를 보내면 다시 호출시 인라인 치환된다. 
*/

// 1. 인라인 함수는 compile time에 이루어진다. 
inline int Add(int a , int b){ return a+b;}

struct Plus
{
	inline int operator() (int a , int b){ return a+b; }
};

template<typename T> void foo(T f)
{
	// std::cout << __PRETTY_FUNCTION__ << std::endl;

	int n = f(1,2);	
};

int main()
{
	Plus p;
	foo(Add); 	// 함수 포인터 전달 foo( int (*f)(int, int) )
		// f(1,2)에서는 Add 주소를 주므로 inline 치환될수 없다. 
		// 주소만 넘기므로 , 그 주소를 받고는 Add가 뭔지는 알수 없다.  compile time에 주소만 알고 있음. 
		// assembler로 보자. makefile안에 넣어둠.
		//

	// foo(Sub); 	// 함수 포인터 전달 foo( int (*f)(int, int))
	
	foo(p); 	// Plus 타입으로 전달 foo(Plus)
			// f.operator()(1,2) 을 compile할때 할수 있다. 
			// compile time에 Plus인지를 알고 있으므로 compile time에 치환 가능하다.
			// inline 치환이 된다. 

	//Minus m;
	//foo(m);		// foo(Minus)   이건 함수가 하나 더 생기는 단점이 생길수도 있다. 
}
