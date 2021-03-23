/* 4_coercion 43 page
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

template <typename T>
class Point
{
    T x, y;
public:
    Point(T a=T(), T b=T()) : x(a),y(b){}
};
// T() : default 생성자

int main()
{
    Point<int>  p1(3  , 4); // 위의 생성자를 부름. 일반 생성자
    Point<int> p2 = p1;     // 복사 생성자 ,  computer가 만들어줌

    Point<double> p3 = p1;  // error : 다른 type에는 복사 생성자가 있을수 없다. 

}
