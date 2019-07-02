/* 12_member_detect1 143 page
- 
*/

#include <iostream>
#include <type_traits>
#include <vector>


template<typename T>
void foo(T& c)
{
    auto n = c.front();
}


int main()
{
    std::vector<int> v = {1,2,3};
}


// cppreference.com  allocator 검색
