/*
- 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

template<typename T> struct default_delete
{
	inline void operator()(T* p)
		// T* p 대신 void*로 하면 안된다. 
		// delete는 소멸자도 부르기 때문이다. 
		// void*는 절대 delete하면 안된다. 
	{
		std::cout << "default delete" << std::endl;
		delete p;
	}
};

struct Freer
{
	// free는 소멸자를 호출하지 않으므로 void* 를 사용해도 됩니다. 
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};

template<typename T, typename D = default_delete<T> >
class unique_ptr
{
	T* obj;
public:
	inline unique_ptr(T* p = 0) : obj(p) {}
	inline ~unique_ptr() 
	{ 
		// delete obj; 
		D d;
		d(obj);
	}

	inline T* operator->(){ return obj; }
	inline T& operator*(){ return *obj; }

	// 복사 생성자와 대입연산자를 삭제 합니다.
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator= (const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int> p1(new int);
	unique_ptr<int,Freer> p2((int*)malloc(100));
		// shared_ptr p1(.. , 삭제자)
		// unique_ptr은 삭제자를 인자로 받지 않는다. template 인자로 **
		
	// 아래 sp1,sp2는 다른 타입? 같은 타입?  답:  같은 타입
	// 같은 타입이므로 , 같은 container에 넣을수 있다.
	// 	확장성은 shared_ptr이 더 좋다.
	// unique_ptr은 p1,p2가 다른 type이 되므로 같은 container 에 넣을수 없다. 
	//  그러나 , unique_ptr이 성능은 더 좋다. 
	std::shared_ptr<int> sp1(new int);
	std::shared_ptr<int> sp2(new int, foo);

	//unique_ptr<void,Freer> p2(malloc(100));
	//	void일때는 operator*()에서 에러가 난다
}
