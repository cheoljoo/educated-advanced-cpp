/* 6_SFINAE2  215 page
- Substitution Failure Is Not An Error
- 핵심 1. 함수 호출시 어떤 함수를 호출하는지는 인자만 가지고 결정한다. 
    - 반환 타입은 관련 없다.
- Substitution Failure Is Not An Error
    - 템플릿을 사용하기로 결정하고 , T를 특정 타입으로 치환할때 실패하면 에러가 아니라 다른 버변의 함수를 사용하게 한다. 
- SFINAE가 적용되는 위치 3곳 (함수 signature에 적용)
    - 1. 함수 반환값 : 가장 많이 사용되는 기술
        - ```template<typename T> typename T::type foo(T n){} ```
    - 2. 함수 인자 타입 : return type이 없는 2개중 하나인 생성자에 사용하고 싶을때
        - ```template<typename T> void foo(T n,typename T::type n2){} ```
    - 3. 템플릿 인자  : 함수의 모양이 복잡해지지 않는 특징이 있다.
        - ```template<typename T, typename T2 = typename T::type> void foo(T n) {} ```
*/

#include <iostream>
//using namespace std;

/*
template<typename T>
void foo(T n)
{ 
    typename T::type n; // 1. SFINAE 가 적용될까요?
                        // 2. 컴파일 에러 일까요?  답
}
*/


void foo(...){ std::cout << "..." << std::endl; }

int main()
{
    foo(10); 
}
