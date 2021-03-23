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
	{
		std::cout << "default delete" << std::endl;
		delete p;
	}
};
template<typename T> struct default_delete<T[]>
{
	inline void operator()(T* p)
	{
		std::cout << "default delete []" << std::endl;
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

// T : int[] 이므로
// default_delete<int[]> 으로 된다. 이것이 아래의 spcialization에도 int[]으로 처리 된다. 
template<typename T, typename D = default_delete<T> >
class unique_ptr
{
    PAIR<D,T*> m; 
public:
	// inline unique_ptr(T* p = 0, const D& del = D()) : m(del,p){}
    template<typename Dx = D>
        inline unique_ptr(T* p = 0,Dx&& del = Dx())
        : m(std::forward<Dx>(del),p) {}

	inline ~unique_ptr() 
	{ 
		m.getValue1()( m.getValue2() );
	}

	inline T* operator->(){ return (m.getValue2()); }
	inline T& operator*(){ return *(m.getValue2()); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator= (const unique_ptr&) = delete;

    // move  계열은 제공
    inline unique_ptr(unique_ptr&& p) noexcept
        : m(std::move(p.m)) 
        {
            p.m.getValue2() = nullptr;  // 이것이 없으면 죽음 T*을 사용했기 때문임.
        }
    inline unique_ptr& operator=(unique_ptr&& p) noexcept
    {
        m = std::move(p.m);
        p.m.getValue2() = nullptr;  // 이것이 없으면 죽음
        return *this;
    }
};
template<typename T, typename D>
class unique_ptr< T[], D >
{
    PAIR<D,T*> m;  // PAIR<D,int*> m
public:
	inline unique_ptr(T* p = 0, const D& del = D()) : m(del,p){}
	inline ~unique_ptr() 
	{ 
		m.getValue1()( m.getValue2() );
	}
    // 배열버젼에서는 []을 제공하는 것이 좋습니다.
    T& operator[](int idx)
    {
        // m.getValue2() : 보관된 포인터 꺼내기
        return m.getValue2()[idx];
    }

	// inline T* operator->(){ return (m.getValue2()); }
	inline T& operator*(){ return *(m.getValue2()); }

    // 복사계열은 금지
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator= (const unique_ptr&) = delete;

};

int main()
{
/*
- 이번 소스에서 변한 것 (2가지)
    1. 생성자가  변경 - forwarding reference 사용
    1. unique_ptr안에 move 생성자 추가
 */
    
    Freer f;
    unique_ptr<int,Freer> p1(new int , std::move(f) );

    unique_ptr<int> p2(new int);

    // unique_ptr<int> p3 = p2;    // error 자원을 독점하기로 했기에 error
    unique_ptr<int> p4 = std::move(p2); // 되어야함.
}