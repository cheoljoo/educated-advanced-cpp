/* 2_traits 115 page : int-to-Type 관련 
- traits : 템플릿 인자 T의 다양한 특질(Traits)를 조사하는 기술.
    - speicialzation을 이용하여 <T*> 로 받을때는 enum {value=다른값}으로 정의하면된다.
    - ::으로 값을 가져오는 것은 enum과 변수 등 이다. 
    - partially_specialization.cpp 참조
*/

#include <iostream>

/*
- is_pointer : 컴파일할때 T가 pointer인지 조사하는 도구
    - 컴파일 할때 사용하는 함수 라는 의미로 meta function 이라고도 한다.
    - 만드는 방법
        - 1. 구조체 템플릿을 만든다.
        - 2. enum { value = false} 를 넣는다.
        - 3. 조건을 만족하는 부분 특수화 버전을 만든다. 그리고, eum {value = true}를 넣는다. 
*/

template<typename T> struct is_pointer
{
    enum {value = false };
};
// 템플릿 부분 특수화 (specialization) 문법
// T의 형태에 따라 다른 구현을 하겠다는 의미.
template<typename T> struct is_pointer<T*>
{
    enum {value = true };
};

template <typename T> 
void foo(T v)
{
    if(is_pointer<T>::value){       // compile할때 처리한다. meta 함수라고도 한다. 
        std::cout << "포인터 " << v << std::endl;
    } else {
        std::cout << "포인터 아님 " <<  v << std::endl;
    }
}

int main()
{
    int n = 10;
    foo(n);
    foo(&n);

}

