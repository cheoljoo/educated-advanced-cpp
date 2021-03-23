/* 2_traits 115 page : int-to-Type 관련 
- traits : 템플릿 인자 T의 다양한 특질(Traits)를 조사하는 기술.
*/

#include <iostream>

/*
- 
*/

template <typename T> void printv(T v)
{
    if(T가 포인터라면){
        std::cout << v << ":" << *v << std::endl;
    } else {
        std::cout << v << std::endl;
    }
}

int main()
{
    int n = 10;
    printv(n);
    printv(&n);

}

