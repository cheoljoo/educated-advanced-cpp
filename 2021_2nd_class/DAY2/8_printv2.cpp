#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// advance 만들기 
// 방법 1. Tag Dispatching - C++98 시절 기술

template<typename T> void xadvance_imp(T& p, int N, std::input_iterator_tag)
{
	while (N--) ++p;
	std::cout << "임의 접근이 아닌 경우" << std::endl;
}
template<typename T> void xadvance_imp(T& p, int N, std::random_access_iterator_tag)
{
	p = p + N;
	std::cout << "임의 접근인  경우" << std::endl;
}
template<typename T> void xadvance(T& p, int N)
{
	xadvance_imp(p, N, typename std::iterator_traits<T>::iterator_category());
}

int main()
{
	//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	//	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	int s[10] = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::begin(s); 
					 
	xadvance(p, 5);  

	std::cout << *p << std::endl;
}
