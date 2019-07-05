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

void foo(int a, int& b)
{
    b = 100;
}

int main()
{
    std::function<void(int)> f;

    int n = 0;
    {
        // int n = 0;
        // f = std::bind(&foo, _1, n); // n이 아니라 n의 값을 고정(보관)
        // 이렇게 block으로 될때 n은 사라지게 되므로 reference로 사용할수가 없다. 
        
        // 그러나 꼭 쓰고 싶으면
        f = std::bind(&foo, _1, std::ref(n)); // n이 아니라 n의 값을 고정(보관)
        // std::cref -> const 참조

    }
    f(10);  // foo(10,n)
    std::cout << n << std::endl;    // 100
}


