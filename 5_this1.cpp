//  5_this
#include <iostream>
//using namespace std;

class Point
{
    int x,y;
public:
    void set(int a, int b)      // set(Point* this,int a, int b)
    {
        x=a;    // this->x =a;
        y=b;    // this->y =b;
    }
    void print() const  // print (const Point* this)
    {
        x=10;           // error : const this->x=10 이 안되기 때문이다.  
    }
};

int main()
{
    Point p1,p2;
    p1.set(10,20);  // set(&p1,10,20)의 의미로 전달됩니다. 
                    // push 20
                    // psuh 10      진짜 인자는 스택으로 
                    // mov ecx,&p1   객체 주소는 레지스터에
                    // call Point::set
}
