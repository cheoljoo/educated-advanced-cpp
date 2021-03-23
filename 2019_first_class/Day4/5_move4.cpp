/*
- 
*/

#include <iostream>
#include <vector>
#include <string>
//using namespace std;

/*
- 
*/

int main()
{
    std::string s1 = "hello";
    //std::string s2 = s1;
    std::string s2 = std::move(s1);

    std::cout << ": " << s1 << std::endl;

    std::vector<int> v1 = { 1,2,3};
    //std::vector<int> v2 = v1;
    std::vector<int> v2 = std::move(v1);
    std::cout << ": " << v1.size() << std::endl;
}
