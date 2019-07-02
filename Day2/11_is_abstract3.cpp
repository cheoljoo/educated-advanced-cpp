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


template<typename T> short test(T (*arr)[2]);     // 추상클래스 일때 실패했으면 함
template<typename T> char test(...){}

template<typename T> struct is_abstract
{
    static constexpr bool value = (sizeof(test<t>(0)) == 1);
};

int main()
{
    bool b = is_abstract<Shape>::value;
    std::cout << b << std::endl;
}
