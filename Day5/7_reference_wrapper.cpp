/*
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

// C++참조: 개념적으로 const 이다.
//      참조가 이동하지 않고 값이 이동합니다. 
int main()
{
    int n1 = 10;
    int n2 = 20;
    int& r1 = n1;
    int& r2 = n2;


    r2 = r1; // 이 한줄의 의미를 잘 생각해보세요.
        // c++은 & 은 기본적을 const이므로 (절대 이동될수 없다.)
        // 그러므로 , 값이 이동하는 것이다. 

    std::cout << n1 << std::endl; //10
    std::cout << n2 << std::endl; //10
    std::cout << r1 << std::endl; //10
    std::cout << r2 << std::endl; //10
}
