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
        std::cout << __PRETTY_FUNCTION__ << std::endl;  
        return *this; 
    }
};


int main()
{
    Test t1;
    Test t2 = t1;               // 무조건 복사 생성자 사용

        // 무조건 move 생성자 사용
        // 예외가 이어도 사용
        // 단지 , 캐스팅 일뿐
    Teest t3 = std::move(t2);   
                                
        // move 생성자의 예외 여부 조사 
        // 예외가 없으면 move 사용
        // 있으면 복사 생성자 사용
    Test t4 = std::move_if_noexcept(t3);

    std::vector<Test> v(5);
    std::cout << "--------------" << std::endl;

    v.resize(7);    // 내부적으로 move_if_noexcept를 사용한다. 

    std::cout << "--------------" << std::endl;
}
