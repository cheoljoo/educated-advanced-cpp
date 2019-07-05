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
    foo(1,2,3,4);
    // bind : N항의 함수 인자를 고정해서 M(<N)항의 함수를 만드는 도구
    std::bind(&foo, 10 , _1 , 3, _2)(5,7); // 10,5,30,7
    std::bind(&foo, 10 , 5 , 3, 7)(); // 10,5,30,7
    std::bind(&foo, _3 , 7 , _1, _2)(5,3,2); //  2,7,5,3
}
