/* 9_printv3  (총정리) 
- 
*/

#include <iostream>
#include <type_traits>
using namespace std;

/*
- 방법 3. if constexprt - c++17 style
*/

// cppreference.com 에서 INVOKE 찾아보세요.
//  possible implementation
template<typename T> void printv(T v)
{
    if constexpr (is_pointer<T>::value)
        cout << v << " : " << *v << endl;
    else 
        cout << v << endl;

}

int main()
{
    int n=0;
    printv(n);
    printv(&n);
}
