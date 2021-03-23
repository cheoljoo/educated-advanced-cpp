/* 9_printv1  (총정리) 
- 
*/

#include <iostream>
#include <type_traits>
using namespace std;

/*
- 방법 1. true_type / false_type을 사용하는 function overloading
*/

template<typename T> void printv_imp(T v,true_type)
{
    cout << v << " : " << *v << endl;
}
template<typename T> void printv_imp(T v,false_type)
{
    cout << v << endl;
}
template<typename T> void printv(T v)
{
    printv_imp(v,std::is_pointer<T>() ); // operator overloading
}

int main()
{
    int n=0;
    printv(n);
    printv(&n);
}
