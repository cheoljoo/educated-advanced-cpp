/*
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

template<typename T>
class unique_ptr
{
	T* obj;
public:
	inline unique_ptr(T* p = 0) : obj(p) {}
	inline ~unique_ptr() { delete obj; }

	inline T* operator->(){ return obj; }
	inline T& operator*(){ return *obj; }

	// 복사 생성자와 대입연산자를 삭제 합니다.
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator= (const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int> p1(new int);
	*p1 = 10;
	unique_ptr<int> p2 = p1; // 이렇게 하면 죽을 것임.
		// 이렇게 쓰지 못하게 하려면 복사 생성자를 못 만들게 해야 한다. 
		// p2 = p1처럼 쓰고 싶으면 , shared_ptr을 사용하라는 것이다.
}
