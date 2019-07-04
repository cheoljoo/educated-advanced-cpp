/*
-  부분특수화 사용 : default_delete
*/

#include <iostream>
//using namespace std;

/*
-  
*/

template<typename T> struct default_delete
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete p;
	}
};
template<typename T> struct default_delete<T[]>
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete[] p;
	}
};

struct Freer
{
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};

template<typename T, typename U> struct PAIR : public T
{
	U v2;
	T& getValue1() { return *this; }
	U& getValue2() { return v2; }

	template<typename A , typename B>
	PAIR(A&& a, B&& b)
		: T(std::forward<A>(a)) 	// 기반 클래스 생성자 호출
		, v2(std::forward<B>(b)){}

	PAIR() = default;
};

// T : int[]
template<typename T, typename D = default_delete<T> >
class unique_ptr
{
    // main 2번째 줄 처럼 사용하면 T=> int[]이므로
    // 아래 코드가 오른쪽 주석처럼 됩니다.
    // error
    PAIR<D,T*> m;   // PAIR<D,int[]*>   int[]*은 존재할수 없다  error
public:
	inline unique_ptr(T* p = 0, const D& del = D()) : m(del,p){}
	inline ~unique_ptr() 
	{ 
		m.getValue1()( m.getValue2() );
	}

	inline T* operator->(){ return (m.getValue2()); }
	inline T& operator*(){ return *(m.getValue2()); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator= (const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int> p1(new int);
	unique_ptr<int[]> p2(new int[10]);

}
