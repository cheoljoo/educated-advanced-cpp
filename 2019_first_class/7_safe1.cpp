//  7_예외안전성1 - 59 page
#include <iostream>
#include <exception>
//using namespace std;


// 예외 안정성 (exception safety)
// 1. 완전 보장 : 예외가 없다. ex) int n=0  int *p = nullptr
// 2. 강력 보장 : 예외가 있지만 잡아서 처리하면 
//                  객체의 상태는 예외 발생 이전 상태가 된다. 
//                  계속 사용가능하다.
// 3. 기본 보장 : 예외가 발생해도 잡으면 자원 누수는 없다.
//                  단, 객체의 상태는 알수 없다. 이어서 사용할수 없다.  

template <typename T>
class Stack 
{
    T buff[10];
    int idx=0;
public:
    void push(const T& a){ buff[idx++] = a; }
    T pop()
    {
        --idx;
        if(idx < 0)
            throw std::out_of_range("stack empty");
        return buff[idx];
    }
};

int main()
{
    Stack<int> s;
    try 
    {
        s.pop();
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    // 여기서 s를 계속 사용해도 될까?
}
