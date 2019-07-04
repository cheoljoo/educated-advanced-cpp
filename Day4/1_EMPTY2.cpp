/* 1_EMPTY2  - 73 page
- 
*/

#include <iostream>
//using namespace std;

/*
- new를 사용하면 operator new()가 호출됩니다.
*/
void* operator new(size_t sz)
{
	void* p = malloc(sz);
	if(p == nullptr)
		throw std::bad_alloc();

	return p;
}

// 2번째 인자는 위와 다르게만 받으면 된다. 
// #define nothrow 1로 하고 
// new(size_t sz,int) 로 놓을수 있다. 
//
// 설명적인 것을 사용하면 좋다.
//
// 함수 오버로딩시 empty을 사용하는 경우가 많이 있습니다.
struct nothrow_t {};		// 1 byte의 최소 요구조건 만족하며 , 딱 nothrow만 넣을수 있게 된다. 
nothrow_t nothrow;	// VS : extern nothrow_t const nothrow;
void* operator new(size_t sz,nothrow_t)
{
	void* p = malloc(sz);
	return p;
}

int main()
{
	try
	{
		int* p1 = new int;  // 메모리 부족시 std::bad_alloc 예외 발생
			// 0으로 return하지 않음.
	}
	catch(std::bad_alloc& b){}


	int* p2 = new(nothrow) int;	// 메모리 부족시 0 반환
	// new(nothrow , "K") 로 하면 new(size_tsz , h , k) 로 뒤로 붙게 된다. 
	if(p2 == nullptr){}
} 
