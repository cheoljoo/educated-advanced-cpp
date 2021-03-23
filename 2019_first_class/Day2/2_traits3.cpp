/* 2_traits3 115 page : int-to-Type 관련 
- traits : 템플릿 인자 T의 다양한 특질(Traits)를 조사하는 기술.
    - speicialzation을 이용하여 <T*> 로 받을때는 enum {value=다른값}으로 정의하면된다.
    - ::으로 값을 가져오는 것은 enum과 변수 등 이다. 
    - partially_specialization.cpp 참조
*/

#include <iostream>

template <typename T> struct is_reference
{ 
    enum { value = 0 };
};
template <typename T> struct is_reference<T&>
{ 
    enum { value = 1 };
};
template <typename T> struct is_reference<T&&>
{ 
    enum { value = 1 };
};

template <typename T> struct is_const
{ 
    enum { value = 0 };
};
template <typename T> struct is_const<const T>
{ 
    enum { value = 1 };
};

int main()
{
    std::cout << is_reference<int>::value << std::endl; // 0
    std::cout << is_reference<int&>::value << std::endl; // 1

    std::cout << is_const<int>::value << std::endl; // 0
    std::cout << is_const<const int>::value << std::endl; // 1

}

