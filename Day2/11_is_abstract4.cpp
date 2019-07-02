/* 11_is_abstract3
- 
*/

#include <iostream>
#include <type_traits>

class Shape
{
public:
    virtual void Draw() = 0;
};


// 어느 함수가 불리는지를 조사하는 것

template<typename T> struct is_abstract
{
    typedef char YES[1];        // 143 page ArrayOne
    typedef char NO[2];

    static template<typename U> NO& test(U* (*arr)[2]);     // 추상클래스 일때 실패했으면 함
    static template<typename U> YES& test(...){}

    static constexpr bool value = (sizeof(test<t>(0)) == sizeof(YES));
};

int main()
{
    bool b = is_abstract<Shape>::value;
    std::cout << b << std::endl;
}
