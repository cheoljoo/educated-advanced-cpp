/* 3_make
- 
*/

#include <iostream>
#include <memory>
using namespace std;

/*
- 
*/
class Point
{
    int x, y;
public:
    Poit(int a, int b){}
};

void foo() {return 0; }
void goo(const unique_ptr<Point>& p , int n){}

int main()
{
    // 아래 한줄은 안전할까요?
    // 아래처럼 실행되면 문제가 발생할수 있다.
    // 1. new Point(1,2)
    // 2. foo() => 여기서 예외가 나오면 1의 코드가 메모리 누수
    // 3. unique_ptr 생성
    goo( unique_ptr<Point>(new Point(1,2) , foo() ) );
        // goo 안의 2개의 함수는 어떤게 먼저 수행될지 모름
        // Point  -> foo -> unique_ptr을 하는데 , foo에서 문제 발생시 자원이 안전하지 않다. 

}
