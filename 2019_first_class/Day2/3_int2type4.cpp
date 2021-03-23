/* 3_int2type4.cpp   115 page
- fail : 6번에서 완성
-  함수 overloading을 사용한다. 
    - foo(3.4) 이면 foo(int) / foo(double) 중에서 foo(double)로 간다.
        - template function이면서 overloading이 되게 해야 한다.
    - 함수는 같고 인수 type만 달라야 한다. 0,1의 값이 다른데 이것을 각기 다른 type으로 인지하게 해야 한다.
        - int2type을 이용하면 0,1이 서로 다른 type이 되므로 overloading이 가능해진다.
*/

#include <iostream>
#include <type_traits>
//using namespace std;

template<typename T> void printv_imp(T v,YES)
{
    std::cout << "pointer" << std::endl;
    std::cout << v << " : " << *v << std::endl;
}
template<typename T> void printv_imp(T v,NO)
{
    std::cout << "not pointer" << std::endl;
    std::cout << v << std::endl;
}
template<typename T>
void printv(T a)
{
    // T가 포인터인지에 따라 다른 함수를 호출하게 한다. 
    printv_imp(a,std::is_pointer<T>::value);
}

int main()
{
    int n=0;
    printv(n); 
    printv(&n); 
}
