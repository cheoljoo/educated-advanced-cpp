/* 4_typename.cpp
- 
*/

#include <iostream>
//using namespace std;

/*
- 클래스이름::???
    - static 변수 
    - enum 상수 
    - typedef  : 이때는 type으로 보내는 것임.
*/

class AAA {
public:
    enum { value = 4 };
    typedef int DWORD;
};

template<typename T> void foo(T a)
{
    // 컴파일러는 아래 한줄을 어떻게 해석해야 할까요?
    // (1) DWROD는 값 (static 변수 or enum 상수)이다.
    // (2) DWORD는 T안에 내포된 타입이다.   ==> template이라고 앞에 붙여주어야함.
    //T::DWORD * p;       // DWORD를 값으로 보고 곱하기 p 하는 코드
    
    typename T::DWORD * p;       // DWORD를 타입으로 해석해 달라는 의미

    /*
    - 핵심 : 템플릿 인자(T)에 의존된 타입을 사용할때는 반드시 앞에 typename을 붙여야 한다!!!
    */
    AAA::DWORD *p2;  // typename이 필요없다
                            // T가 아니라 명확한 이름(AAA)사용!
}

int main()
{
    AAA aaa;
    foo(aaa);

}
