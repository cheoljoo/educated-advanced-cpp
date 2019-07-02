/* 7_enable_if2   77 page
- 정수가 아닌 경우 실패하게 하고 싶다.
    - static_assert : compile time에 assert하는 것임. 
        - 조건을 만족하지 못하면 무조건 error
    - enable_if : 조건을 만족하지 못하면 템플릿을 사용하지 않음
        - 동일 이름의 다른 함수가 있으면 사용가능
- https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h
```cpp
template<typename TYPE>
typename std::enable_if<traits<TYPE>::has_trivial_copy>::type  ==> 뒤의 인자가 없으므로 void
inline
copy_type(TYPE* d, const TYPE* s, size_t n) {
    memcpy(d,s,n*sizeof(TYPE));
}
```
*/

#include <iostream>
//using namespace std;
#include <type_traits>

/*
- 
*/

/*
template<typename T> T gcd(T arg1 , T arg2)
{
    // arg1 , arg2 의 최대 공약수를 반환한다고 가정해 봅시다. 
    
    // 정수가 아닌 경우 실패하게 하고 싶다.
    // static_assert : 1번째 인자가 false이면 컴파일 중지
    static_assert(std::is_integral<T>::value,"not integral");

    return 0;
};
*/

template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
gcd(T arg1,T arg2)
{
    return 0;
}

// double 버젼의 함수 제공
double gcd(double arg1 , double arg2)
{
    std::cout << "double" << std::endl;
    return 0;
}

int main()
{
    gcd(10,6);  // int
    gcd(3.4,2.4); // float
}

