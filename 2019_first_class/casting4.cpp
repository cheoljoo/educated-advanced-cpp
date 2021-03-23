// casting4.cpp
// const_cast는 const와 volatile을 제거할때 사용하는 것이다. 
// const만 제거하는 것이고 , type을 바꾸지는 못한다. 


#include <iostream>

using namespace std;

#if 0
int main()
{
	const int c = 10 ;

	// 상수성을 제거하는 캐스팅 
	int* p1 = static_cast<int*>(&c);	// error

	int* p2 = reinterpret_cast<int*>(&c);	// error
		// 서로 다른 타입의 포인터는 되는데 , 상수성을 제거 할수 없다. 
	
	int* p3 = const_cast<int*>(&c);		// ok


	volatile int n=10;
	int* p4 = static_cast<int*>(&n); 	// error

	int* p5 = const_cast<int*>(&n); 	// ok
		// const_cast는 const와 volatile을 제거할때 사용하는 것이다. 
}

#else


// 질문 . 아래 코드를 완성해 보세요.
int main()
{
	const int c = 10;

	// char* p = &c;  // error
	
	// c의 주소를 char*에 담아보세요
	char *p = reinterpret_cast<char*>(const_cast<int*>(&c));

	char* p1 = (char*)&c;  // ok .. C style casting
}
#endif
