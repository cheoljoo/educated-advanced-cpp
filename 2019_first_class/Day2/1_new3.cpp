/*  1_new3.cpp  
- "android source github"   aosp-mirror
    - platform_system_core utils/TypeHelpers.h    enable_if , new 등 모두 들어가 있는 code
    - https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h
        - copy_type
*/
#include <iostream>
#include <vector>

#if 0
int main()
{
    // 1. vector의 메모리 관리 기술
    std::vector<int> v(10);

    v.resize(7); // 원리를 생각해봅시다.
        // 새로 할당해서 copy하지 않고 , 그냥 재사용하면서 capacity라는 변수로 관리
    
    std::cout << v.size() << std::endl;     // 7
    std::cout << v.capacity() << std::endl;     // 10

    v.push_back(5);
    std::cout << v.size() << std::endl;     // 8
    std::cout << v.capacity() << std::endl;     // 10

    v.shrink_to_fit();
    std::cout << v.size() << std::endl;     // 8
    std::cout << v.capacity() << std::endl;     // 8

    v.push_back(5);
    std::cout << v.size() << std::endl;     // 9
    std::cout << v.capacity() << std::endl;     // 16  더 크게
}

#else
class DBConnect
{
public:
    DBConnect(){ std::cout << "Connect DB" << std::endl; }
    ~DBConnect(){ std::cout << "Disconnect DB" << std::endl; }
};

int main()
{
    std::vector<DBConnect> v(5);
    v.resize(3);    // 줄어든 메모리는 파괴하지 않습니다 
                    // 하지만 소멸자를 호출해야 합니다.
                    // 소멸자의 명시적 호출이 필요합니다.

    v.resize(4);    // 메모리는 이미 있으므로
                    // 생성자의 명시적 호출이 필요합니다. 
                    // placement new를 사용해서 생성자 호출
}
#endif
