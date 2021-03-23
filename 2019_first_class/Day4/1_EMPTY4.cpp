/*
- 
*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
//using namespace std;

/*
- 
*/

int main()
{
	// std::vector<int> v = {1,2,3,4,5};
	std::list<int> v = {1,2,3,4,5};

	auto p = v.begin();

	// p를 3칸 전진하고 싶습니다. 가장 좋은 코드는 무엇일까요?
	// p = p +3; 	// list를 사용했을대는 p+3이 안된다. 
	std::advance(p,3);   // 이것은 vector , list 모두 사용가능
				// STL에서 가장 좋은 코드 이다. 
				// 임의 접근이 아니면 ++을 3번해준다. 
}

