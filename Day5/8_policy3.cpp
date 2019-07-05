/*
- 
*/

#include <iostream>
#include <vector>
//using namespace std;

/*
- 
*/

struct Point
{
    int x,y;
    Point(int a=0,int b=0){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Point(){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
};
int main()
{
    std::allocator<Point> ax;
    Point* p1 = ax.allocate(2);     // 메모리만 할당함 
    ax.construct(&p1[0],1,2);
    ax.construct(&p1[1]);

    ax.destroy(&p1[0]);
    ax.destroy(&p1[1]);
    ax.deallocate(p1,2);

}
