/*
-  배열도 해결
*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
//using namespace std;

/*
- 
*/

/*
// 5개의 개념을 type으로 만든다. 이때 empty를 써야 한다. 
// 반복자 카테고리 개념을 타입화 합니다. 
// STL에 이미 다 정의되어져있음.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_iterator_tag : bidirectional_iterator_tag {};
*/

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


// 반족자의 형태
// 1. 클래스로 만들어진 객체 형태
// 2. raw pointer
// 위의 2개의 차이점을 해결하는 도구
template<typename T> struct iterator_traits
{
	using iterator_category = typename T::iterator_category;
};
template<typename T> struct iterator_traits<T*>
{
	using iterator_category = std::random_access_iterator_tag;
};

template<typename T>
void advance(T& p, int n)
{
	// T : 반복자
	// p = p + n;
	
	// advance_imp(p, n , typename T::iterator_category() );	// 임시객체
	advance_imp(p, n , typename iterator_traits<T>::iterator_category() );	// 임시객체
	// 한 단계를 더 거친다. 간접층을 만든다. 
}

int main()
{
	// std::vector<int> v = {1,2,3,4,5};
	// std::list<int> v = {1,2,3,4,5};
	int v[5] = {1,2,3,4,5};

	//auto p = v.begin();	// v가 배열이면 error
	auto p = std::begin(v);  // v가 배열이어도 ok

	std::advance(p,3);   
}

/*
- 입력 (컨테이너에서 꺼내 오는 것)
- 출력 (컨테이너에 넣는 것)
- STL 5가지 반복자 category
	- 입력 반복자 : 입력 , ++
	- 출력 반복자 : 출력 , ++
	- 전진형 반복자 : 입력 , ++ , 멀티패스 		// ex. 싱글 리스트 반복자
	- 양방향 반복자 : 입력 , ++ , -- , 멀티패스 	// ex. 더블 리스트 반복자
	- 임의 접근 반복자 : 입력 , ++ , -- , + , - , [] , 멀티패스  // ex. vector : 연속된 메모리와 유사
		- deque는 연속적이 아닐수도 있는데 + 을 지원한다. 메모리가 일부분이라도 연속이어 list 대시 성능 향상이 기대

- 멀티 패스란 주어진 구잔을 반복자 p1 , p2 가 같은 값을 볼수 있으면 된다. 
	- 보장 못하는 것은 보는 것은 되는데 , 입력 버퍼의 경우에는 꺼내가면 없어지므로 안된다.
	- find같은 것은 멀티패스를 보장할 필요가 없다. 주어진 구간을 1번만 보면 된다.
	- sort같은 것들은 멀티 패스를 보장하는 반복자만 가능하다.
	- 일반적인 컨테이너들은 모두 멀티 패스를 보장한다. 
*/
