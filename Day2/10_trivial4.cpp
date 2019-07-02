/* 10_trivial4
- fail
- trivial : 생성자 , 복사 생성자 , 소멸자 , 대입연산자 등이 하는 일이 없을 경우 'trivial하다' 라고 한다.
*/

#include <iostream>
#include <type_traits>
#include <stdio.h>
#include <string.h>
#include <atomic>


/*
- atomic을 만들려면 복사 생성자도 만들면 안되다. 그러므로 trivial 개념이 필요하다. 
 */

struct Point
{
    int x,y;
   // int x,y,z; 이렇게 해서 64bit가 넘아가면 lock_free가 안된다고 에러가 나온다.
   
    Point() {}
    Point(const Point& p):x(p.x),y(p.y){}
};
std::atomic<int> an;
std::atomic<Point> ap;

int main()
{
    int n = an.load();      // 멀티 쓰레드에서 안전하게 load

    //Point pt = ap.load();

    std::cout << an.is_lock_free() << std::endl; // 1
    std::cout << ap.is_lock_free() << std::endl; // 1

    /*
    // n = n + 1  어셈
    __asm
    {
        move eax,n
        add eax,1
        mov n,eax
    }
    // 멀티스레드에 안전하게 1 증가
    // 인텔 계역 CPU는 lock prefix 사용
    // lock free : OS의 lock을 사용하지 않는다는 의미
    __asm
    {
        lock inc n
    }
    */
}

