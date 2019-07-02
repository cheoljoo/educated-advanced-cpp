/* 3_int2type5
- 0,1을 서로 다른 type으로 설정하기 위해서
    - 0,1은 일반적으로는 같은 int
*/

#include <iostream>
//using namespace std;

/*
- 
*/

// 템플릿 인자로는 "타입"뿐 아니라 "정수"를 보낼수도 있습니다 .
template<int N> struct int2type     // 115 page
{
    enum { value = N};
};
int main()
{
    foo(0);
    foo(1); // 0,1은 같은 타입. foo(0)과 foo(1)은 동일한 함수를 호출
    int2type<0> t0;
    int2type<1> t1; // t0 , t1은 다른 type이다. 
    foo(t0);
    foo(t1);    // t0,t1은 다른 type이므로 foo(t0)/foo(t1)은 다른 함수를 부른다. 
}
