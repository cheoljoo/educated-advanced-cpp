#include <iostream>
#include <vector>
#include <list>

/*
void print_first_element(std::vector<int>& v)
{
	int n = v.front();
	std::cout << n << std::endl;
}
*/
/*
template<typename T> 
void print_first_element(std::vector<T>& v)
{
	T n = v.front();
	std::cout << n << std::endl;
}
*/

template<typename T>
void print_first_element(T& v)
{
	// T : list<double>
	// T::value_type : list<double>::value_type => double

	// T::value_type n = v.front(); // error

	typename T::value_type n = v.front(); // ok

	std::cout << n << std::endl;
}
int main()
{
	//std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	//std::vector<double> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<double> v = { 1,2,3,4,5,6,7,8,9,10 };

	print_first_element(v);
}

// STL 의 모든 컨테이너는 자신이 저장하는 타입을 외부에 알려주고 있습니다.
template<typename T> class list
{
public:
	//typedef T value_type; // 핵심.. list가 저장하는 타입을 알려주기 위해
	using value_type = T; // C++11 스타일 
};

list<int>::value_type n; // 





