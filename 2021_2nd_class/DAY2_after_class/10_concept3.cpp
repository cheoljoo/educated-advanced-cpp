// 10_concept3
#include <iostream>
#include <vector>

// find_if 로 하지 않아도 enable_if 를 사용하면 find()를 만들어서
// 값인 경우와 함수인경우의 구별이 가능합니다.
// 하지만 STL 만들때는 enable_if 개념이 없었습니다.

template<typename Iter> 
void sort(Iter first, Iter last)
{
	std::cout << "sort 기본 버전" << std::endl;
}
template<typename Iter, typename Pred>
void sort(Iter first, Iter last, Pred f)
{
	std::cout << "sort 조건자를 받는 버전" << std::endl;
}
template<typename Cont>
void sort(Cont c)
{
	std::cout << "sort 컨테이너 버전" << std::endl;
}
template<typename Cont, typename Pred>
void sort(Cont c, Pred f)
{
	std::cout << "sort 컨테이너 조건자 버전" << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	sort(v.begin(), v.end()); // 만들어 봅시다.

	// 비교정책을 교체 가능하게 설계하자.
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );

	sort(v); // 컨테이너를 받는 버전

	sort(v , [](int a, int b) { return a < b; });
}


