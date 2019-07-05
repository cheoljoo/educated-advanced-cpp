/*
- 
*/

#include <iostream>
#include <functional>
//using namespace std;

/*
- 
*/

template<typename T> class reference_wrapper
{
    T* ptr;
public:
    reference_wrapper(T& p){ ptr = &p; }
    
    // 변환연산자: 반환 타입을 표기하지 않는 특징이 있다.
    // 객체가 다른 타입으로 변환되기 위해 필요
    operator T&() { return * ptr; }
    T& get() const{ return *ptr; }
};


// reference_wrapper: 이동가능한 참조
//      참조끼리 대입시 참조가 이동
int main()
{
    int n1 = 10;
    int n2 = 20;
#if 1
    reference_wrapper<int> r1 = n1;
    reference_wrapper<int> r2 = n2;

    int& r3 = r1; // 진짜 참조와 호환 가능해야 한다. 
        // 서로 type이 다를때는 같은 type이 있는지 찾아서 copy한다. 
        // r1.operator int&()라는 "변환연산자" 함수가 있는지 찾게 된다.
        //
    std::cout << n1 << std::endl; //10
    std::cout << n2 << std::endl; //20
    std::cout << r1 << std::endl; //10
    std::cout << r2 << std::endl; //20
    std::cout << r3 << std::endl; //10
#else
    std::reference_wrapper<int> r1 = n1;
    std::reference_wrapper<int> r2 = n2;


    r2 = r1; // 이 한줄의 의미를 잘 생각해보세요.
    r2.get() = 30;

    std::cout << n1 << std::endl; //30
    std::cout << n2 << std::endl; //20
    std::cout << r1 << std::endl; //30
    std::cout << r2 << std::endl; //30
#endif

}
