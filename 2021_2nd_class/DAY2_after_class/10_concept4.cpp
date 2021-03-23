// 10_concept3
#include <iostream>
#include <vector>
#include <concepts> 

// 모든 컨테이너는 begin(), end() 함수가 있습니다.
// 특정 타입이 container 여야 한다는 concept
template<typename T> 
concept Container = requires(T c)
{
	{ c.begin() };
	{ c.end() };
};

template<typename Iter> requires std::bidirectional_iterator<Iter>
void sort(Iter first, Iter last)
{
	std::cout << "sort 기본 버전" << std::endl;
}
template<typename Iter, typename Pred> requires std::bidirectional_iterator<Iter>
void sort(Iter first, Iter last, Pred f)
{
	std::cout << "sort 조건자를 받는 버전" << std::endl;
}
template<typename Cont> requires Container<Cont>
void sort(Cont c)
{
	std::cout << "sort 컨테이너 버전" << std::endl;
}
template<typename Cont, typename Pred> requires Container<Cont>
void sort(Cont c, Pred f)
{
	std::cout << "sort 컨테이너 조건자 버전" << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	sort(v.begin(), v.end()); // 만들어 봅시다.

	// 비교정책을 교체 가능하게 설계하자.
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	sort(v); // 컨테이너를 받는 버전

	sort(v, [](int a, int b) { return a < b; });
}


