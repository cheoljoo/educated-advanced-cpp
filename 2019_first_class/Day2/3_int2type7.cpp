/* 3_int2type7.cpp   115 page
- int2type을 발전시켜서 C++11 표준에 추가된 template
    - integral
*/

#include <iostream>
//using namespace std;
#include <type_traits>


/*
//- int2type을 발전시켜서 C++11 표준에 추가된 template
template<typename T,int N> struct integral_constant     // 115 page  : 시험문제
{
    enum { value = N};  // c++11 이전 스타일

    static constexpr T value = N ; // C++11 이후 스타일
                        // constexpr을 사용한 컴파일 시간 상수
};

integral_constant<int,0> t0;
integral_constant<int,1> t1;
integral_constant<short,1> s1;

integral_constant<bool,true> b0;
integral_constant<bool,false> b1;

// true/false : 참 ,거짓을 나타내는 값. 같은 타입
// true_type / false_type : 참, 거짓을 나타내는 값. 다른 타입
typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;
    // 객체는 임시로 true_type()  , false_type()


// C++ 표준의 is_pointer는 아래처럼 만들었습니다. (:기반클래스) 
template<typename T> struct is_pointer : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};
*/

template<typename T> void printv_imp(T v,std::true_type)   // type만 적어주어도 됨.
{
    std::cout << "pointer" << std::endl;
    std::cout << v << " : " << *v << std::endl;
}
template<typename T> void printv_imp(T v,std::false_type)
{
    std::cout << "not pointer" << std::endl;
    std::cout << v << std::endl;
}
template<typename T>
void printv(T a)
{
    // T가 포인터인지에 따라 다른 함수를 호출하게 한다. 
    printv_imp(a,std::is_pointer<T>() );
            // 클래스이름()  : 임시로 사용할 객체 생성
}
