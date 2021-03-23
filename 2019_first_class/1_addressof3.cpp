// 1_addressof3.cpp  : 7 page
#include <iostream>
using namespace std;

class Point
{
	int x,y;
public:
	Point(){x=0;y=0;}
	// 내 조소를 알지 말라 기법 
	// 주소를 나타낼때는 0대신 nullptr을 사용하자 - c++11
	Point* operator&() const { return nullptr; }
};


template<typename T>
T* myaddressof(T& obj)
{
	//return reinterpret_cast<T*>( 
	//	&(reinterpret_cast<char&>(
	//	const_cast<T&>(obj) )) );
	//
	//7 page 아래 소스 : 2번째 3번째 캐스팅 순서가 중요
	return reinterpret_cast<T*>( 
			&(const_cast<char&>(		// const를 없앤다. 
				reinterpret_cast<const volatile char&>(obj) )) ); // const를 계속 유지 , 없어도 추가
}

// error가 없도록 수정해라.
int main()
{
	const Point pt;

	const Point* p1 = myaddressof(pt);		
	// return reinterpret_cast<T*>( &(reinterpret_cast<char&>(const_cast<T&>(obj) )) ) 일때는 
		// error :  T 는 const Point가 된다.  그러므로 const_cast<T& 에서 에러가 난다.

	cout << p1 << endl; // 진짜 주소가 나오게 위코드 수정

	const Point* p2 = addressof(pt);		
	cout << p2 << endl; // 진짜 주소가 나오게 위코드 수정

}

