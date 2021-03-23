/*
-  is_poiner_v remove_pointer_t
*/

#include <iostream>
#include <type_traits>
//using namespace std;

/*
- 
*/

/*
template<typename T>
typename std::enable_if<  std::is_pointer<T>::value , int > :: type
foo(T a )
{
}
*/
// 위코드를 _t  _v 버젼을 사용해서 변경해 보세요.
// 1. 함수 반환 타입을 이용한 SNINAE
template<typename T>
std::enable_if_t<  std::is_pointer_v<T>, int >
foo(T a )
{
    return 0;
}

// 2. 함수 인자를 사용한 SFINAE
template<typename T>
int 
goo(T a , std::enable_if_t<  std::is_pointer_v<T>, int > = 0)
{
    return 0;
}

// 3. template 인자를 사용한 SFINAE
// template의 인자로 int 도 받을수 있다.
template<typename T, 
    std::enable_if_t<  std::is_pointer_v<T>, int > = 0
        >
int 
hoo(T a)
{
    return 0;
}

int main()
{
}
