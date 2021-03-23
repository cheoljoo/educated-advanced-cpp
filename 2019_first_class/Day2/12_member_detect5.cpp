/* 12_member_detect5 143 page
- 
*/

#include <iostream>
#include <type_traits>
#include <vector>
#include <array>
#include <complex>


struct Point
{
	int x;
	int y;
};



int main()
{
	int n = 0;

	int* p1 = &n;	// ok
	//int* p2 = &Point::y; // error

	// Point안에 있는 integer member의 주소를 p2에 담는다
	int Point::*p2 = &Point::y; // ok .. 멤버의 주소
					// pointer to member
					
	std::cout << p2 << std::endl;	// 1
	printf("%d\n",p2);		// 4

	// *p2는 offset이다. 
	Point pt;
	pt.*p2 = 10;	// 결국 pt.y = 10 과 같은 의미
			// .* : pointer to member operattor
}


// cppreference.com  allocator 검색
