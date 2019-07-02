/* 2_traits4 115 page : int-to-Type 관련 
- traits : 템플릿 인자 T의 다양한 특질(Traits)를 조사하는 기술.
    - speicialzation을 이용하여 <T*> 로 받을때는 enum {value=다른값}으로 정의하면된다.
    - ::으로 값을 가져오는 것은 enum과 변수 등 이다. 
    - partially_specialization.cpp 참조
*/

#include <iostream>

/*
- c++11 부터 다양한 traits를 표준으로 제공합니다.
*/
#include <type_traits>
using namespace std;

int main()
{
    std::cout << is_reference<int>::value << std::endl; // 0
    std::cout << is_reference<int&>::value << std::endl; // 1

    std::cout << is_const<int>::value << std::endl; // 0
    std::cout << is_const<const int>::value << std::endl; // 1

}

