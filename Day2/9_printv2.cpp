/* 9_printv2   77 page
- 
*/

#include <iostream>
//using namespace std;
#include <type_traits>  // 이 안에 is_pointer등의 traits와 enable_if 있음.

/*
- 아래의 내용은 CGA_RDL로 정의되는 문법을 구현하는 template에서도 주로 사용하는 것이다.
    - template 의 의미를 가지면 어쩔 수 없나보당.  난 2000년 초에 쓴건데!!
- 방법 2. enable_if를 사용하는 방법
*/


// 포인터 일때만 사용할 템플릿
template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type         // void
printv(T v)
{
    std::cout << v << " : " << *v << std::endl;
}

// 포인터 아닐때만 사용할 템플릿
template<typename T>
typename std::enable_if<!std::is_pointer<T>::value>::type         // void
printv(T v)
{
    std::cout << v << std::endl;
}

int main()
{
    int n= 0 ;
    printv(n);
    printv(&n);
}

