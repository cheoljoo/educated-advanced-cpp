/*  1_new2.cpp  103 page
- "android source github"   aosp-mirror
    - platform_system_core utils/TypeHelpers.h    enable_if , new 등 모두 들어가 있는 code
    - https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h
        - copy_type
*/
#include <iostream>
//using namespace std;

/*
- 핵심 1. new의 2가지 사용법
    - new Point(1,1) : 메모리 할당 후 생성자 호출
    - new(p) Point(1,1) : 이미 존재하는 메모리(주소p)에 생성자 호출
        - placement new (위치 지정 new)
- 핵심 2. 생성사 호출 없이 메모리만 할당하는 방법
    - operator new (메모리크기)
- 핵심 3. 
    - delete p1; 소멸자 호출 , 메모리 해지
    - operator delete(p1) : 메모리만 해지
*/

class Point
{
    int x, y;
public:
    Point(int a , int b) : x(a),y(b)
    {
        std::cout << "Point()" << std::endl;
    }
};


int main()
{
    // 1. 0,0으로 초기화된 point를 힙에 한개 만들어 보세요.
    Point* p1 = new Point(0,0);
    

    // 2.  0,0으로 초기화된 Point를 힙에 10개 만들어보세요.
    // default생성자가 Point[]에 대해서는 없다. 
    // Point* p2 = new Point[10];  // error. 디폴트생성자가 필요
    
    // 멤모리 할당과 생성자 호출을 분리하면 항상 편리하다.  
    // <default 생성자가 없을때 분리해서 처리>
    Point* p2 = static_cast<Point*>( operator new(sizeof(Point)*10) );
        // 아직 객체는 아님. 생성자가 호출 안됨.

    // 10개의 메모리에 대해서 생성자 호출
    for(int i=0;i<10;i++){
        new(&p2[i]) Point(0,0);     // 기출시험문제
    }

    // 사용후에는 
    // 1. 소멸자 호출
    for(int i=0;i<10;i++){
        p2[i].~Point();
    }

    // 메모리만 해지
    operator delete(p2);
}
