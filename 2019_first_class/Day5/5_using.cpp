/*
-  is_poiner_v remove_pointer_t
*/

#include <iostream>
#include <type_traits>
//using namespace std;

/*
-  c++14부터 아래 코드를 제공합니다. 
*/
// using 문법
template<typename T>
using remove_pointer_t =  typename std::remove_pointer<T>::type;

// variable template 이라는 문법 
template<typename T>
bool is_pointer_v = std::is_pointer<T>::value;

template<typename T>
void foo(T a)
{
    // bool b = std::is_pointer<T>::value;
    bool b = is_pointer_v<T>::value;

    // typename std::remove_pointer<T>::type t;
    remove_pointer_t<T> t;

    //위의 것들은 모두 std 에 있다. 
}

int main()
{
    int n;
    foo(&n);
}
