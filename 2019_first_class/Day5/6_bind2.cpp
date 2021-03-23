/*
- 
*/

#include <iostream>
#include <functional>
//using namespace std;
using namespace std::placeholders;

/*
- 
*/

void foo(int a, int b, int c, int d)
{
    printf("%d %d %d %d\n",a,b,c,d);
}

int main()
{
    void(*f1)(int); // 인자가 한개인 함수 주소만 담을수 있다.

    // c++11에서 추가된 함수 포인터 역할의 템틀릿
    // 주로 bind와 같이 사용한다.
    std::function<void(int)> f;
    f = std::bind(&foo, _1 , 0,0,0);;
    f(10);  // 10 ,0,0,0
}

/*
class Button
{
void (*handler)();
std::function<void()> handler;  // 앞으로 인자가 몇개가 올지 모름
}
 */
