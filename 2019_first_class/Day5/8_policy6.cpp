/*
- 
*/

#include <iostream>
//using namespace std;

template<typename T> struct MyAlloc {};
// MyAlloc<int> a;    
//
template<typename T,        // type
        int N,              // 정수
        template<typename> class AT>    // template (틀)
class Test
{
    // AT a; // error. AT는 타입이 아닌 템플릿 입니다.
    AT<T> ax;
};

Test<int,10, MyAlloc> t;

/*
- 
*/


/*
template<typename T, typename Ax> class List
{
    // Node의 Allocator가 필요!
};
*/

// Modern C++ Design 책 - 안드레이 알렉산드레스큐
//  visitor pattern  -> C++17 표준에 들어옴.
template<typename T, template<typename> class AT> class List
{
    struct Node {};
    // AT ax;  // error. AT는 템플릿
    //AT<T> ax; // MyAlloc<int> ax;
    AT<Node> ax;    // MyAlloc<Node> ax;
};

int main()
{
    //List<int,MyAlloc<int>> s;
    List<int,MyAlloc> s;

}
