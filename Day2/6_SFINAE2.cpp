/* 6_SFINAE2  215 page
- Substitution Failure Is Not An Error
- 핵심 1. 함수 호출시 어떤 함수를 호출하는지는 인자만 가지고 결정한다. 
    - 반환 타입은 관련 없다.
- Substitution Failure Is Not An Error
    - 템플릿을 사용하기로 결정하고 , T를 특정 타입으로 치환할때 실패하면 에러가 아니라 다른 버변의 함수를 사용하게 한다. 
*/

#include <iostream>
//using namespace std;

template<typename T>
typename T::type foo(T n){ std::cout << "T" << std::endl; return 0;}
    // T와 같은 type으로 return하는데 , T가 들어간 type으로 선언하므로 typename을 붙여준다.
    // int::type foo(int n){} 함수를 생성하려고 한다.  그러나, int::type이라는 것은 없다. 

void foo(...){ std::cout << "..." << std::endl; }

int main()
{
    foo(10); 
}
