/* 11_is_abstract2
- 
*/

#include <iostream>
#include <type_traits>

/*
- 핵심 
    - 1. 함수 템플릿 버전과 가변인자 버젼의 2개의 함수를 함든다.
    - 2. 템플릿 버젼은 조건을 만족하지 않으면 실패하게 만든다.
- T arg : 추상클래스라면 실패. 하지만 인자를 보낼때 객체가 필요!
- T* arg : 추상클래스라도 포인터는 만들수 있다. 
- T(*arr)[2] :  배열을 가리키는 포인터 - 추상 클래스는 배열을 가리키는 포인터를 만들수 없다.
    - 배열에서는 크기가 있어야 하는데 , 추상은 크기를 구할수 없다. 
*/

class Shape
{
public:
    virtual void Draw() = 0;
};


// 추상 클래스는 객체를 만들지 못한다. 
// return 값의 크기를 조사해보면 어떤게 불렸는지 알 수 있다.

//template<typename T> short test(T* (*arr)[2]){}     // 추상클래스 일때 실패했으면 함
    // 아래줄 처럼 구현부를 뺌. 실제로 수행할 것은 아님.
template<typename T> short test(T (*arr)[2]);     // 추상클래스 일때 실패했으면 함
template<typename T> char test(...){}

int main()
{
    // test<Shape>(0); // 호출 . 평가되는 표현식

    // 호출하지 말고 , 어느 함수가 호출되는지만 조사.
    int n = sizeof(test<Shape>(0));

    std::cout << n << std::endl;
}
