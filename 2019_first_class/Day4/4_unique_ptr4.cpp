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
    D d;    // 삭제자를 보관합니다.   ~소멸자에서는 삭제
public:
	inline unique_ptr(T* p = 0, const D& del = D()) : obj(p), d(del) {} // d(del) 복사 생성자
	inline ~unique_ptr() 
	{ 
        // D d;
		// delete obj; 
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
		

	//unique_ptr<int,[](int*)(free(p);} > p3((int*)malloc(100)); // error lambda표현식의 결과는 타입이 아니라 객체
    // 삭제자로 사용할 람다표현식을 만들어서 auto 변수에 담는다.
    auto del = [](void* p){ free(p); std::cout << "lambda" << std::endl; };
    unique_ptr<int,decltype(del)> p3(new int , del);
    
	//unique_ptr<int,decltype([](int*)(free(p);}) > p2((int*)malloc(100));
            // lambda는 default 생성자가  없다. 
            // 그러므로 , D d; 에서 문제가 된다. 

    // foo(a);  // 함수 인자는 객체가 필요
    // list<int>;  // 템플릿 인자는 테이타 타입

}
