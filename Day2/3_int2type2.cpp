/* 3_int2type2.cpp   115 page
-  fail
*/

#include <iostream>
#include <type_traits>
//using namespace std;

/*
- 
*/

template<typename T>
void printv(T a)
{
    if(std::is_pointer<T>::value) // case 1 : if (false)
        std::cout << a << ":" << *a << std::endl;
    else 
        std::cout << a << std::endl;
}

int main()
{
    int n=0;
    printv(n); //1 : error
    printv(&n); //2
}
