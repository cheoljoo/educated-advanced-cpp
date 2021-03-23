/*
- 
*/

#include <iostream>
#include <functional>
#include <thread>
//using namespace std;

/*
- 
*/

void foo(int a, int b) { b = 100; }

int main()
{
    int n = 0;
    //std::thread t(&foo,1,n);    // thread의 생성자에서 threadt생성
            // 즉 , 이 순간 thread생성됩니다.
            // n은 값

    std::thread t(&foo,1,std::ref(n));
    t.join();
    std::cout << n << std::endl;

}
