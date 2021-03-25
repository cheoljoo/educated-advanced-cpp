#include <algorithm>
#include <functional>  
#include <vector>
using namespace std;

// 람다 표현식의 원리

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::find_if(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });
}






