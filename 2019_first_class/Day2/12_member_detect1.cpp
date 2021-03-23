/* 12_member_detect1 143 page
- 
*/

#include <iostream>
#include <type_traits>
#include <vector>


// list : 멤버함수 sort() 제공
// vector : 멤버함수 sort() 없음.  일반함수 sort() 사용
template<typename T>
void foo(T& c)
{
    auto n = c.front();
}


int main()
{
    std::vector<int> v = {1,2,3};
    foo(v);

    MyAllocator<int> ax;
    allocator_traits<MyAllocator<int>> at(ax);
    	// allocator_traits가 내거 안에 있으면 그것을 쓰고 , 없으면 traits것을 사용한다.. 

    int n= at.max_size(); // 1. MyAllocator에 max_size가 있으면 사용
    			// 2. 없으면 allocator_traits의 max_size 사용
			// 가사함수로 만들어도 되지만, 이것은 inline으로 되므로 빠름
}


// cppreference.com  allocator 검색
