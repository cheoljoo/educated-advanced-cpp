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

//  중요한 이야기
//  setter 2번이 가장 좋은 방법이고  
//  1개로 해결하려면 setter 4번으로 하면 됨
class Object
{
    Test data;
public:
    Object(){}
    // void setData(Test d){ data = d; }

    // setter만들기 1. const & - 항상 복사 사용
    // void setData(const Test& d){ data = d; }

    // setter만들기 1. const & - 항상 복사 사용 (const 는 move될수 없다.)
    // void setData(const Test& d){ data = std::move(d); }

    // setter 2. 2개 만들자
    // const & 버젼과 && 버젼 으로 2개 만들자
    // void setData(const Test& d){ data = d; }
    // void setData(Test&& d){ data = std::move(d); }

    // setter 3. call by value는 아주 나쁠까?
    // move가 빠르면 call by value 1개만 써서 해결해도 된다.
    // void setData(Test d){ data = std::move(d); }

    // setter 4. forwarding reference
    template<typename T> void setData(T&& d)
    {
        // data = d;   // 1 무조건 복사 
        // data = std::move(d);    // 2  무조건 move
        data = std::forward<T>(d);    // 3
    }
};

int main()
{
    Object obj;
    Test data;

    obj.setData(data);  
        // setter 2. 복사 대입 1회
        // setter 3. 복사 생성 1회 , move 대입 1회

    obj.setData(std::move(data)); 
        // setter 2. move 대입 1회
        // setter 3. move 생성 1회 , move 대입 1회
}
