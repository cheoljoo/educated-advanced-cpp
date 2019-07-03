/* 3_forwarding_reference10
- pair를 만들어보자
*/

#include <iostream>
//using namespace std;

/*
- 
*/

// pair : 2개의 값을 보관하는 구조체
template<typename T, typename U> struct pair
{
	T first;
	U second;

	/*
	// 생성자 모양 1. call by value
	//pair(T a , U b) : first(a) , second(b) {}

	// 생성자 모양 2. non const lvalue reference
	//pair(T& a , U& b) : first(a) , second(b) {}

	// 생성자 모양 3. const lvalue reference
	pair(const T& a , const U& b) : first(a) , second(b) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
		// 모든 참조는 const 입니다. 
		// pair<int& 을 주면
		// 뒤에 const U&을 할때 int&이 자동으로 const를 포함하므로
		// const U&의 const가 사라집니다.  왜냐면 &자체가 const를 쓰지 않아도 의미를 가지고 있기 때문입니다.
	*/
	//pair(T&& a , U&& b) : first(a) , second(b) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	

	// 생성자 모양 4 : C++11 이후 스타일
	template<typename A , typename B>
	pair(A&& a,B&& b) : first(std::forward<A>(a)) , second(std::forward<B>(b)) 
	{ std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main()
{
	int a = 10 , b = 20;
	pair<int,int> p1(10,20);
	pair<int,int> p2(a,b);
	pair<int&,int&> p3(a,b);
		/*
		const int c = 10;
		const int& r = c;
		int& r2 = r;
		*/
	pair<int&&,int&&> p4(10,20);   
		// 생성자 모양 3에서 
		//int&& <- const int & 이어야 하는데 이게 안된다는 것이다. rvalue = lvalue를 넣을수 없다. 
	
	std::pair<int,double> p5;
 
	// call by value 일때 type deduction 할때는 const가 사라진다. 
}
