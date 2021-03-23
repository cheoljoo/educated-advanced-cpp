/* 10_trivial2
- trivial : 생성자 , 복사 생성자 , 소멸자 , 대입연산자 등이 하는 일이 없을 경우 'trivial하다' 라고 한다.
*/

#include <iostream>
#include <type_traits>
#include <stdio.h>
#include <string.h>

/*
- 복사를 할때 얕은 / 깊은 복사중에서 선택하기 위해서  trivial한지를 조사한다.
    - trivial하지 않으면 ...
*/

struct Point
{
    int x,y;
};

/*
template <typename T>
void copy_type(T* d, T* s , size_t n)
{
    if(std::is_trivially_copy_constructible<T>::value){
        memcpy(d,s,sizeof(T)*n);    // 이것만 하면 얕은 복사
    } else {
        //  복사 생성자가 하는 일이 있으면 각 요소에 대해 복사 생성자 호출
        while(n--)
        {
            // new T;       // 메모리 할당 + 생성자 호출
            // new T(*s);   // 메모리 할당 + 복사 생성자 호출
            // new(d) T;    // d 메모리에 디폴트 생성자 호출
            new(d) T(*s);   // d 메모리에 복사 생성자 호출
            ++d, ++s;
        }
    }
}
*/

template <typename T>
typename std::enable_if<std::is_trivially_copy_constructible<T>::value>::type
copy_type(T* d, T* s , size_t n)
{
    memcpy(d,s,sizeof(T)*n);    // 이것만 하면 얕은 복사
}
template <typename T>
typename std::enable_if<!std::is_trivially_copy_constructible<T>::value>::type
copy_type(T* d, T* s , size_t n)
{
    //  복사 생성자가 하는 일이 있으면 각 요소에 대해 복사 생성자 호출
    while(n--)
    {
        // new T;       // 메모리 할당 + 생성자 호출
        // new T(*s);   // 메모리 할당 + 복사 생성자 호출
        // new(d) T;    // d 메모리에 디폴트 생성자 호출
        new(d) T(*s);   // d 메모리에 복사 생성자 호출
        ++d, ++s;
    }
}

int main()
{
    char s1[10] = "hello";
    char s2[10];

    // strcpy(s2,s1);  // 메모리 할당이 없고 , 기존 메모리 복사
    
    copy_type(s2,s1,10);    // 만들어 봅시다.
}
