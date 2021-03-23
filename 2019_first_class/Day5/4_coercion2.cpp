/* 4_coercion 43 page
- coercion
    - int가 double로 변환되면 , Point<int>도 Point<double>로 변환되어야 한다. 
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

    // generic 복사 생성자
    //template<typename U>
    //Point(const Point<U>& p) : x(p.x) , y(p.y) {}

    // 복사 생성자의 구현을 밖으로 뽑아보려함.

    template<typename U> friend class Point; //  모든 Point들은 friend
};
// T() : default 생성자

// member template의 외부 구현 
// 클래스 템플릿의 멤버 템플릿의 외부 구현
template<typename T> template<typename U>
Point<T>::Point(const Point<U>& p) : x(p.x) , y(p.y) 
{
}

int main()
{
    Point<int>  p1(3  , 4); // 위의 생성자를 부름. 일반 생성자
    Point<int> p2 = p1;     // 복사 생성자 ,  computer가 만들어줌

    Point<double> p3 = p1;  // error : 다른 type에는 복사 생성자가 있을수 없다. 

}
