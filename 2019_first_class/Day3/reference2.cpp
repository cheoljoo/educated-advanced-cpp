/* reference2.cpp
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

template<typename T> void foo(const T* a)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T> void goo(const T* a)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
	int n = 0;
	foo(&n); 		// a가 가리키는 것은 const
	foo<int*>( (int**)&n );


	goo(n);		// goo(const int&)
	//goo<int&>(n);	// goo( int& const&)
			// 모든 참조는 const 입니다. 따라서  const는 빠집니다. 
			// goo(int& &) 가
			// goo(int &)가 됩니다. 
	
	int n1 = 10;
	int& r = n;   // r이 한번 set되면 가리키는 곳은 절대 바뀌면 안된다. 
			// 그러므로 int& const r = n; 이 되는 것이다.
			// 그래서 위에서 모든 참조는 const라고 하는 것이다. 

	r = n1;  	// r을 변경?  
			// r이 가리키는 곳을 변경? 답
}
