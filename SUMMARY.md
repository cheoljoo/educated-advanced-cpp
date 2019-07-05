# Summary
1. 주소를 얻고 싶을때 함수 :  addressof
1. 생성,소멸,복사생성자가 없는 것 : trivial
1. 예외가 없음 : noexcept
1. Error일때 죽지 않고 코드 생성을 하지 않음 : SFINAE
1. 특정인자 고정 : bind
1. enable_if or enable_if_t  is_integral_v
1. move
1. 할당 / 생성자의 분리
1. lambda : 디폴트 생성자가 없다. ( C++20부터는 제공)
1. perfect forwarding :  ```A&&    std::forwarding<A>()```
1. explicit 생성자
1. int2type
