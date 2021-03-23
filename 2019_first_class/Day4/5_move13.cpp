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

template<typename T, typename U> struct pair
{
    T first;
    U second;

    //pair(const T& a, const T& b) : first(a) , second(b) {}  // 여기는 무조건 copy

    template<typename A = T , typename B = U>
        pair(A&& a = A(),B&& b = B()) :
            first(std::forward<A>(a)),
            second(std::forward<B>(b) ){}
};

int main()
{
    // int x,y;
    // pair<int,int> p1(std::move(x),std::move(y));
    // pair<int,int> p2;

    Test x,y;
    pair<Test,Test> p1(std::move(x),std::move(y));
    pair<Test,Test> p2;
}
