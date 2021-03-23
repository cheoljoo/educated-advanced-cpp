//  7_예외안전성2 - 59 page
#include <iostream>
#include <exception>
#include <stdexcept>
//using namespace std;


// 예외 안정성 (exception safety)
// 1. 완전 보장 : 예외가 없다. ex) int n=0  int *p = nullptr
// 2. 강력 보장 : 예외가 있지만 잡아서 처리하면 
//                  객체의 상태는 예외 발생 이전 상태가 된다. 
//                  계속 사용가능하다.
// 3. 기본 보장 : 예외가 발생해도 잡으면 자원 누수는 없다.
//                  단, 객체의 상태는 알수 없다. 이어서 사용할수 없다.  

// stl은 제거와 반환을 분리  : 강력 보장을 지키기 위해서 이다.

// STL이 제거와 반호나을 동시에 하지 않는 이유
// 1. 예외 안정성의 강력보장을 지키기 위해
// 2. 참조 반환을 통해서 임시객체를 제거하기 위해서 
template <typename T>
class Stack 
{
    T buff[10];
    int idx=-1;
public:
    void push(const T& a){ buff[++idx] = a; }
    /*
    T pop()
    {
        if(idx < 1)
            throw std::out_of_range("stack empty");

        --idx;
        return buff[idx];
    }
    */

    // 제거와 반환을 동시에 하면 강력 보장을 지킬수 없다. 
    // 제거와 반환은 분리한다.
    T& top() { return buff[idx]; }  // 반환만
    void pop() { --idx; } // 제거만
};

class People {};

int main()
{
    Stack<People> s;
    People p;
    s.push(p);
    try 
    {
        People p = s.top(); // 꺼내기만
        s.pop(); // 제거만
        /*
        People p = s.pop();  // 1. s.pop() 호출
                             // 2. People의 복사 생성자 호출
                             //     => 여기서 예외가 발생하면
                             //     */
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    // 여기서 s를 계속 사용해도 될까?
}
