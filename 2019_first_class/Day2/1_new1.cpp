/*  1_new1.cpp  103 page
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
    // malloc : 메모리만 할당
    // new : 메모리를 할당 + 생성사 호출
    Point* p1 = new Point(0,0);
    delete p1; // 소멸자 호출 후 메모리 해지

    // 메모리할당과 생성자 호출 분리
    // 1. 메모리만 할당
    Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));    // malloc과 유사
                        // operator new의 반환값이 void *

    std::cout << "주소: " << p2 << std::endl;

    // 2. 할당된 메모리에 생성자 호출
    new(p2) Point(0,0);

    // 메모리 할당과 생성자 호출을 분리한 경우 
    // 소멸자 호출과 메모리 해지도 분리한다.

    // 3. 소멸자 호출
    p2->~Point();  

    // 4. 메모리만 해지
    operator delete(p2);  
}
