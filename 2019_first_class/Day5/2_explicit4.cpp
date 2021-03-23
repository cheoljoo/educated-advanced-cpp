/*
- 
*/

#include <iostream>
using namespace std;

/*
- 
*/

class Vector
{
public:
    explicit Vector(int size){}
    explicit Vector(int size , int value)    // 1
    {
        cout << "1" << endl;
    }
    Vector(initializer_list<int> s) // 2 
    {
        cout << "2" << endl;
    }
};

int main()
{
    Vector v4 = 10 ; // error
    Vector v5 = {10} ; // ok

    Vector v1(10,3);    // 10개를 3으로 초기화
    Vector v2{10,3};    // 2번생성자가 없으면 1번 생성자으로 간다
    Vector v2{10,3,1,2,3,4};


}
