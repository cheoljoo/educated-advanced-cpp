/*
- 
*/

#include <iostream>
#include <string>
#include <vector>
//using namespace std;

/*
- noexcept 지시어 : 함수가 예외가 없음(있음)을 알리는 것
    - void foo() noexcept
    - void foo() noexcept(true)
    - void foo() noexcept(false)

- noexcept 연산자 : 표현식이 예외가 있는지 조사하는 것
    - bool b = noexcept(foo())
    - bool b = noexcept(T())
    - bool b = noexcept(T(T()))
*/

class Test
{
    int data;
    std::string s = "hello";
public:
    Test() {}   // resource = new int;
    ~Test() {}
    Test(const Test& t):data(t.data),s(t.s){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(const Test& t)
    {
        data = t.data;
        s = t.s;
        std::cout << __PRETTY_FUNCTION__ << std::endl;  return *this; 
    }


/*
- move와 예외
- move 계열 함수를 만들때는 예외가 나오지 않게 만들고
- 예외가 없다고 꼭 컴파일러에게 알려주자. 
- noexcept : 예외가 없다. 
- noexcept(true) : 예외가 없다. 
- noexcept(false) : 예외가 있다.

- sizeof(표현식)  : 표현식의 크기
- decltype(표현식)  : 표현식의 타입
- noexcept(표현식)  : 표현식의 예외 여부 조사  2개 이상이면 || &&

- move는 하다가 실패하면 뒤로 되돌릴수 없어서 강력 보장을 지킬수 없다. 
- 그러므로, stl에서는 기본적으로는 copy로 처리한다. 
- noexcept를 넣으면 move로 처리
*/
    /*
    Test(Test&& t) noexcept(   
                            noexcept(std::string(std::string()))
                           ) :data(t.data),s(std::move(t.s)){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    */
    Test(Test&& t) noexcept(   
                            std::is_nothrow_move_constructible<std::string>::value
                           ) :data(t.data),s(std::move(t.s)){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(Test&& t)  noexcept (
                            std::is_nothrow_move_constructible<std::string>::value
                                        )
    {
        data = std::move(t.data);
        s = std::move(t.s);
        std::cout << __PRETTY_FUNCTION__ << std::endl;  return *this; 
    }
};


/*
1. 사용자가 복사와 move를 모두 제공하지 않으면 컴파일러가 모두 제공해준다.
1. 사용자가 복사 계열 함수를 제공하면 컴파일러는 move 계열을 제공하지 않는다.

- rule of 0 : 사용자가 직접 자원을 관리하지 않으면 소멸자복사계열2개,move계열 2개를 만들 필요가 없다.
    - 컴파일러가 모두 제공
    - 내부적으로 char* 와 같이 raw pointer를 사용하지 말아라. char*가 필요하면 string을 쓰고 , array가 필요하면 vector를 사용해라. 
 */

class Object
{
    Test data;
public:
    Object(){}
    Object(const Object& o) : data(o.data){}
};


int main()
{
    Object o1;
    Object o2 = o1;
    Object o3 = std::move(o2);
}
