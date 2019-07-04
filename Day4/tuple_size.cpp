/*
- 
*/

#include <iostream>
#include <tuple>
//using namespace std;

/*
- 
*/

struct Empty {};


int main()
{
    std::tuple<Empty,int> t1;
    std::cout << sizeof(t1) << std::endl;
        // g++ : 4
        // vc++ : 8

}
