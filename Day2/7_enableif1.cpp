/* 7_enable_if1   77 page
- enable_if<A,B>
    - A가 true이면 B를 그대로 , B가 없으면 void type 으로 반환
    - A가 false 이면 error
*/

#include <iostream>
//using namespace std;

/*
- 
*/

template<bool b, typename T=void> struct enable_if
{
    typedef T type;
};

// 부분특수화에서는 default값을 적지 않아도 일반화의 적용을 받는다. 
template<typename T> struct enable_if<false,T>
{
};

int main()
{
    // 아래 코드에서 n의 타입을 적어 보세요.
    enable_if<true,int>::type n1;       // int 
    enable_if<true,double>::type n2;        // double 
    enable_if<true>::type n3;   // void , 변수 선언 안되므로 error

    // 1번째 인자가 false인 경우 type은 없습니다. 
    enable_if<false,int>::type n4;  // error
    enable_if<false,double>::type n5;   // error
    enable_if<false>::type n6;  // error
}
