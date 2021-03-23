/* 6_SFINAE1  215 page
- Substitution Failure Is Not An Error
*/

#include <iostream>
//using namespace std;

/*
- overloading resolution : 함수 찾는 순서 (float로 시작)
    - 1. float : exactly matching - float
    - 2. template 를 사용해서 float 생성
    - 3. promotion (테이터 손실이 없는 변화) - double
    - 4. standard conversion (표준 타입까지 변환)
        - int , short가 있는 경우에는 어디로 갈지 모름 (compile error)
    - 5. 어떤 후보도 없을때 가변인자 사용
*/

void foo(float n){ std::cout << "float" << std::endl; }     // 1
void foo(int n){ std::cout << "int" << std::endl; }         // 4
void foo(double n){ std::cout << "double" << std::endl; }   // 3
void foo(...){ std::cout << "..." << std::endl; }           // 5

template<typename T>
void foo(T n){ std::cout << "T" << std::endl; }             // 2

int main()
{
    float f = 3.4f;

    //- overloading resolution : 함수 찾는 순서 (float로 시작)
    foo(f); 
}
