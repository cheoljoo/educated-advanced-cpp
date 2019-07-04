/*
- enable_if 사용 
:: concept1.cpp 참조하라.

*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <type_traits>
//using namespace std;

/*
- 
*/


/*
// 각 컨테이너의 반복자 설계시 자산이 무슨 종류의 반복자 인지 알려주어야 합니다.
template<typename T> class vector_iterator
{
public:
	// 모든 반복자 안에는 반드시 아래 iterator_category 가 정의되어 있어야 한다. 
	// typedef random_iterator_tag iterator_category;
	using  iterator_category = std::random_access_iterator_tag;
};
template<typename T> class list_iterator
{
public:
	// 모든 반복자 안에는 반드시 아래 iterator_category 가 정의되어 있어야 한다. 
	using  iterator_category = std::bidirectional_iterator_tag;
};

*/

/*
template<typename T> 
void advance_imp(T& p , int n , std::random_access_iterator_tag)
{
	std::cout << "random access" << std::endl;
	p += n;
}
template<typename T> 
void advance_imp(T& p , int n , std::input_iterator_tag) // input_iterator_tag 에서부터 파생되어오기때문에 
	// true_type , false_type과 같다.
{
	std::cout << "no random access" << std::endl;
	while(n--) ++p;
}
*/

// enable_if 버젼으로 변경합시다. 

template<typename T> 
typename std::enable_if< 		// typename을 또 쓰는 것은 ::type 을 static으로 보지 않고 type으로 보기 위한 것이다.  
	std::is_same< 
		typename std::iterator_traits<T>::iterator_category,
		std::random_access_iterator_tag
    >::value
                       >::type  // void
advance(T& p , int n)
{
	std::cout << "random access" << std::endl;
	p += n;
}
template<typename T> 
typename std::enable_if< 
	!std::is_same< 
		typename std::iterator_traits<T>::iterator_category,
		std::random_access_iterator_tag>::value>::type
advance(T& p , int n)
	// true_type , false_type과 같다.
{
	std::cout << "no random access" << std::endl;
	while(n--) ++p;
}


/*
template<typename T>
void advance(T& p, int n)
{
	// T : 반복자
	// p = p + n;
	
	//advance_imp(p, n , typename T::iterator_category() );	// 임시객체
	advance_imp(p, n , typename iterator_traits<T>::iterator_category() );	// 임시객체
	// 한 단계를 더 거친다. 간접층을 만든다. 
}
*/

int main()
{
	// std::vector<int> v = {1,2,3,4,5};
	// std::list<int> v = {1,2,3,4,5};
	int v[5] = {1,2,3,4,5};

	//auto p = v.begin();	// v가 배열이면 error
	auto p = std::begin(v);  // v가 배열이어도 ok

	advance(p,3);   
}
