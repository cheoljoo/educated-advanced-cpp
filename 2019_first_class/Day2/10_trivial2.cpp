/* 10_trivial2
- trivial : 생성자 , 복사 생성자 , 소멸자 , 대입연산자 등이 하는 일이 없을 경우 'trivial하다' 라고 한다.
*/

#include <iostream>
#include <type_traits>
using namespace std;

class Test
{
public:
    virtual void foo() { std::cout << "foo" << std::endl; }
};

int main()
{
    bool b = std::is_trivially_default_constructible<Test>::value;

    cout << b << endl;
}
