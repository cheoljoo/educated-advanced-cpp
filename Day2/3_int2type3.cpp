/* 3_int2type3.cpp   115 page
- fail
*/

#include <iostream>
#include <type_traits>
//using namespace std;

/*
- 포인터인 경우와 아닌 경우로 분리해서 2개의 함수 템플릿를 만든다.  
    - (template으로 만들어야 사용할때만 코드 만듦)
*/
template<typename T> void printv_imp_pointer(T v)
{
    std::cout << "pointer" << std::endl;
    std::cout << v << " : " << *v << std::endl;
}
template<typename T> void printv_imp_not_pointer(T v)
{
    std::cout << "not pointer" << std::endl;
    std::cout << v << std::endl;
}
template<typename T>
void printv(T a)
{
    // if문 : 실행 시간 조건문
    //          조건의 결과에 상관없이 컴파일 할때는
    //          아래 2개의 함수 템플릿 모두 사용된다고 
    //          컴파일러가 생각해서 2개 함수 모두 인스턴스화 됩니다. 방법 실패!!!
    if(std::is_pointer<T>::value)
        printv_imp_pointer(a);
    else 
        printv_imp_not_pointer(a);
}

int main()
{
    int n=0;
    printv(n); 
    printv(&n); 
}
