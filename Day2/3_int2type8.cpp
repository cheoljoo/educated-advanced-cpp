/* 3_int2type8.cpp
- 
*/

#include <iostream>
#include <type_traits>
//using namespace std;

/*
- 포인터 여부에 따라 다르게 처리하는 방법
    - C++17이전 
        - 1. (C++11) is_pointer<T>::value 사용
        - 2. (C++11) true_type/false_type을 사용한 함수 오버로딩
*/

/* c++17 이전
```cpp 
tempate <typename T> void foo_imp(T v, true_true){}
tempate <typename T> void foo_imp(T v, false_true){}

template<typename T> void foo(T v)
{
    // 1. (C++11) is_pointer<T>::value 사용
    if(std::is_pointer<T>::value)
    {
        // 단 , 아래와 같은 표현식은 사용할수 없다.
        // *v = 10; // error
    } else {
    }

    // 2. (C++11) true_type/false_type을 사용한 함수 오버로딩
    //  foo_imp안에서는 *v=10 사용가능
    foo_imp(v, std::is_pointer<T>() );

}
```
*/

// 3. c++17이후
template<typename T> void foo(T v)
{
    // if constexpr : 컴파일 시간 if 문
    if constexpr (std::is_pointer<T>::value)
    {
        //*v = 10;
        std::cout << v << " : " << *v << std::endl;
    } else {
        std::cout << v << std::endl;
    }
}

int main()
{
    int n=0;
    foo(n);
    foo(&n);
}
