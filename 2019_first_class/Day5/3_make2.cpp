/* 3_make
- 
*/

#include <iostream>
#include <memory>

/*
- 
*/
class Point
{
    int x, y;
public:
    Point(int a, int b){}
};

int  foo() {return 0; }
void goo(const std::unique_ptr<Point>& p , int n){}

// unique_ptr을 만드는 함수
template<typename T,typename ... ARGS>
std::unique_ptr<T> make_unique(ARGS&& ... args)
{
    return std::unique_ptr<T>(new T(std::forward<ARGS>(args)...));
}

int main()
{
    goo( std::unique_ptr<Point>(new Point(1,2)) , foo()  );

    goo(make_unique<Point>(1,2) , foo() );
    // goo(std::make_unique<Point>(1,2) , foo() );

    std::unique_ptr<Point> up = std::make_unique<Point>(1,2);

}
