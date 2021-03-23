/*
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

template<typename T> struct Test
{
    typedef T type;

        // 구조체 안의 구조체
    template<typename U> struct Object {};
};

template<typename T> void foo(T a)
{
    // T안에 type 형태의 변수 n을 만들어보세요.
    // T  Object "" o
    typename T::type n;
    //typename T::Object<double> o;   // error .  Object가 템플릿이라는 사실을 모른다.

    typename T::template Object<double> o; // ok 
}

int main()
{
    Test<int>::type n;  // int
    Test<int>::Object<double> o;

    Test<int> t;
    foo(t);
}
