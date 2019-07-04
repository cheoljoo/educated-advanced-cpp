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
	/*
	std::vector<int> v = {1,2,3};
	auto p1 = v.begin();
	++p1;	// ok
	--p1;	// ok
	p1 = p1 + 3;	// ok

	std::list<int> s = {1,2,3};
	auto p2 = s.begin();
	++p2;	// ok
	--p2;	// ok
	p2 = p2 + 3;	// error : stl에서는 성능향상을 보이지 않는 것은 제공하지 않는다.
		// 성능이 좋다고 오해하면서 사용할수 있기 때문이다. 

	std::forward_list<int> fs = {1,2,3};	// signle list
	auto p3 = fs.begin();
	++p3; 	// ok
	--p3; 	// error : 자료 구조 특성상 안된다. 
	p3 = p3 + 3; 	// error 
	*/


	std::list<int> s = {1,2,3,4,5,6,7,8,9,10};
	auto p = std::find(s.begin() , s.end() , 5);
		// find 알고리즘의 1,2번째 인자는 반복자 입니다.
		// 최소 요구 조건은 무엇일까요? 입력 반복자
		// 5가지 종류중 골라 보세요
	std::reverse(s.begin() , s.end() ); // 최소 조건 :  양방향 반복자 (--)
		// 현재 lotto645 에서는 compile error : std에서 지원하지 않는 함수
	//std::sort(s.begin() , s.end()); // quick sort
		// 임의 접근 반복자 => 반을 잘라야 한다. (-)
		// list 이므로 조건을 만족하지 못하므로 error
	s.sort();  // 퀵이 아닌 다른 알고르즘.  list는 member함수로 sort가 제공된다.

	// 질문 !
	std::vector<int> v = {1,2,3};
	// v.sort();   // 이 멤버 함수가 있을까요?
	//   없다. 일반 함수 (알고리즘) sort를 사용하면 된다. 
	
	// std::find();
	// cppreference.com 에서 find 찾아보세요.
	// 	template< class InputIt, class T >
	// 	InputIt find( InputIt first, InputIt last, const T& value );
	// 	Input Iterator가 필요하다.
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
