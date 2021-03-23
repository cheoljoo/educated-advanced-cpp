/* 8_policy 183 page (Policy Clone)
- template인자로 동기화 정책을 받자
- 단위 전ㄴ략 다지안 (policy based design)
- webkit 소스 "source/wrf/wrf/nolock.h" 
*/

#include <iostream>
//using namespace std;

/*
- C++20 부터는 concept이라는 것을 이용해서 
여기는 lock / unlock이 필요함을 
문서 대신에 concept으로 source에 정의를 하는 것이다. 
*/
// 동기화 정책을 담는 정책 클래스를 제공합니다.
struct nolock
{
    inline void lock(){}
    inline void unlock(){}
};
struct posix_mutex_lock
{
    inline void lock(){}    // pthread_utex_acquire()
    inline void unlock(){}
};

template<typename T , typename ThreadModel = nolock> class List
{
    ThreadModel tm;
public:
    void push_front(const T& a)
    {
        tm.lock();
        //....
        tm.unlock();
    }
};
//----------------------------------------------
List<int,nolock> s;    //  전역 변수.  멀티쓰레드에 안전하지 않다. 

int main()
{
    s.push_front(10);
}
