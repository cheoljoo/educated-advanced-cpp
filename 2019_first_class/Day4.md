

# Day4

------------

## 대입연산자 vs 생성자   및 복사 vs move (C++11) 구분
- A a ; 디폴트 생성자
- A a1 = a ; 복사 생성자
- A a2 = std::move(a) ;  move 생성자
- b1 = a ; 복사 대입연산자
- b2 = std::move(a);  move 대입연산자

## Empty

### Empty class 
-  empty class : non static 멤버 데이터가 없는 클래스
    - static member는 있어도 됨.
    - 크기가 1로 정의함.
```cpp
struct AAA
{
};

int main()
{
	AAA aaa;
	std::cout << sizeof(aaa) << std::endl;	// 1
} 
```

- [source 1_EMPTY1  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/1_EMPTY1.cpp)


---------

### new로 memory할당  실패시  처리 방법
- new를 사용하면 operator new()가 호출됩니다.
- new operator
    - 함수 오버로딩을 이용한다. 
    - new (P) type -> operator new (sizeof(type) , P)
        - P를 empty를 이용하여 딱 그 값인 "nothrow"가 들어오게 한다. 
```cpp
// std::bad_alloc
void* operator new(size_t sz)
{
	void* p = malloc(sz);
	if(p == nullptr)
		throw std::bad_alloc();

	return p;
}

// nothrow : return 0
struct nothrow_t {};		// 1 byte의 최소 요구조건 만족하며 , 딱 nothrow만 넣을수 있게 된다. 
nothrow_t nothrow;	// VS : extern nothrow_t const nothrow;
void* operator new(size_t sz,nothrow_t)
{
	void* p = malloc(sz);
	return p;
}
```

1. std::bad_alloc 예외 발생   new int;
```cpp
	try
	{
		int* p1 = new int;  // 메모리 부족시 std::bad_alloc 예외 발생
			// 0으로 return하지 않음.
	}
	catch(std::bad_alloc& b){}
```

1. 메모리 부족시 0 반환    new(nothrow) int;
```cpp
	int* p2 = new(nothrow) int;	// 메모리 부족시 0 반환
	// new(nothrow , "K") 로 하면 new(size_tsz , h , k) 로 뒤로 붙게 된다. 
	if(p2 == nullptr){}
```

- [source 1_EMPTY2  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/1_EMPTY2.cpp)


---------

### STL 5가지 반복자 category
- STL 5가지 반복자 category
	1. 입력 반복자 : 입력 , ++
		- ```struct input_iterator_tag {}; ```
	1. 출력 반복자 : 출력 , ++
		- ```struct output_iterator_tag {}; ```
	1. 전진형 반복자 : 입력 , ++ , 멀티패스 		// ex. 싱글 리스트 반복자
		- ```struct forward_iterator_tag : input_iterator_tag {}; ```
	1. 양방향 반복자 : 입력 , ++ , -- , 멀티패스 	// ex. 더블 리스트 반복자
		- ```struct bidirectional_iterator_tag : forward_iterator_tag {}; ```
	1. 임의 접근 반복자 : 입력 , ++ , -- , + , - , [] , 멀티패스  // ex. vector : 연속된 메모리와 유사
		- ```struct random_iterator_tag : bidirectional_iterator_tag {}; ```
		- deque는 연속적이 아닐수도 있는데 + 을 지원한다. 메모리가 일부분이라도 연속이어 list 대시 성능 향상이 기대

- 입력 (컨테이너에서 꺼내 오는 것)
- 출력 (컨테이너에 넣는 것)
- 멀티 패스란 주어진 구잔을 반복자 p1 , p2 가 같은 값을 볼수 있으면 된다. 
	- 보장 못하는 것은 보는 것은 되는데 , 입력 버퍼의 경우에는 꺼내가면 없어지므로 안된다.
	- find같은 것은 멀티패스를 보장할 필요가 없다. 주어진 구간을 1번만 보면 된다.
	- sort같은 것들은 멀티 패스를 보장하는 반복자만 가능하다.
	- 일반적인 컨테이너들은 모두 멀티 패스를 보장한다. 

- 각 type에 따른 반복자
```cpp
	std::vector<int> v = {1,2,3};       // ramdom access
	auto p1 = v.begin();
	++p1;	// ok
	--p1;	// ok
	p1 = p1 + 3;	// ok

	std::list<int> s = {1,2,3};     // bidirectional
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
```

- 함수에 따른 반복자의 최소 조건
    - find : 입력 반복자
    - reverse : 양방향 반복자
    - sort : 임의 접근 => quicksort이며 반으로 잘라야 한다. 
- cppreference.com 에서 find 찾아보세요.
```cpp
	template< class InputIt, class T >
	InputIt find( InputIt first, InputIt last, const T& value );
	//Input Iterator가 필요하다.
```

- [source 1_EMPTY3  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/1_EMPTY3.cpp)


---------

### std::advance 구현
- std::advance(p,3)
- p = p + 3 list / vector등 모두사용가능
    - vector에서는 +3
    - list에서는 ++ 3번
```cpp
	std::list<int> v = {1,2,3,4,5};
	auto p = v.begin();
	std::advance(p,3);   // 이것은 vector , list 모두 사용가능
```

- [source 1_EMPTY4  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/1_EMPTY4.cpp)


---------

- advance_imp(iterator , n , category) 를 두어 구현  for container
    - 함수 오버로딩 
```cpp
template<typename T>
void advance(T& p, int n)
{
	// T : 반복자
	// p = p + n;
	
	advance_imp(p, n , typename T::iterator_category() );	// 임시객체
}
	std::list<int> v = {1,2,3,4,5};
	auto p = v.begin();	// v가 배열이면 error
	std::advance(p,3);   
```
- [source 1_EMPTY5  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/1_EMPTY5.cpp)


---------

- advance_imp(iterator , n , category) 를 두어 구현  for 배열
    - 함수 오버로딩 
    - 배열 처리 위해서 ```typename iterator_traits<T>::iterator_category() ```
```cpp
template<typename T>
void advance(T& p, int n)
{
	// T : 반복자
	// p = p + n;
	
	// advance_imp(p, n , typename T::iterator_category() );	// 임시객체
	advance_imp(p, n , typename iterator_traits<T>::iterator_category() );	// 임시객체
	// 한 단계를 더 거친다. 간접층을 만든다. 
}
	int v[5] = {1,2,3,4,5};
	auto p = std::begin(v);  // v가 배열이어도 ok
	std::advance(p,3);   
```

- [source 1_EMPTY6  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/1_EMPTY6.cpp)


---------

-   advance 구현 using enable_if without advance_imp 
```cpp
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
```

- [source 1_EMPTY7  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/1_EMPTY7.cpp)


---------

## EBCO : Empty Base Class Optimization
- EBCO : Empty Base Class Optimization
	- empty class가 기반 클래스가 되면 크기가 0으로 계산된다. 
	- c++ 표준의 unique_ptr이 이것을 사용한다.
	- 함수 객체는 거의다 empty : 기반클래스로 올린다. 
 
### Empty Base Class Optimization
- Empty가 상속이면 크기를 0으로 최적화 해준다.
```cpp
class Empty {};
class BBB : public Empty
{
	int b;
};

	std::cout << sizeof(BBB) << std::endl; // 4
```

- [source 2_EBCO  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/2_EBCO.cpp)


---------

### EBCO를 이용한 struct PAIR memory 줄이기 : PAIR(Empty,int>
- 일반적으로 선언 : ```template<typename T, typename U> struct PAIR```
- empty base class를 이용한 memory 줄이기 : 앞의 인자를 base class로 둔다
    - ``` template<typename T, typename U> struct PAIR : public T ```
    - T가 empty class인지 아닌지에 따라 할일들이 달라진다 -> [EBCO3](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/2_EBCO3.cpp)
```cpp
// T,U를 member로 가지는 것과 
// 상속 받아도 memory에는 (T ,U)가 들어간다.
// *this를 사용하면 T를 가리키게 된다. 
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

	PAIR<Empty,int> p;
	std::cout << sizeof(p) << std::endl;	// 8->4
```

- [source 2_EBCO2  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/2_EBCO2.cpp)


---------

### PAIR의 완벽한 처리 : PAIR<int,Empty> 도 처리
-  Empty일때만 상속으로 가게
- PAIR<int,Empty> 처리 되게
	- PAIR<int,Empty> p2;
	- PAIR<int,Empty> p2;으로 보내면 std::is_empty<T>::value가 false일 것이다.
- 아래 소스가 boost 라이브러리의 "compress_pair" 입니다. 
- c++ 표준인 unique_ptr을 만들때 이 기술이 사용됩니다. 
- 부분 특수화 이용
```cpp
template<typename T , typename U , bool b = std::is_empty<T>::value > struct PAIR;
// 결국 위의 PAIR은 사용하지 않고 아래의 2개만 사용하게 됩니다.
// 이 경우는 선언만 해도 됩니다. 

template<typename T, typename U> struct PAIR<T,U,false>
{
	T v1;
	U v2;
	T& getValue1() { return v1; }
	U& getValue2() { return v2; }

	template<typename A , typename B>
	PAIR(A&& a, B&& b)
		: v1(std::forward<A>(a))
		, v2(std::forward<B>(b)){}

	PAIR() = default;
};

// T,U를 member로 가지는 것과 
// 상속 받아도 memory에는 (T ,U)가 들어간다.
// *this를 사용하면 T를 가리키게 된다. 
template<typename T, typename U> struct PAIR<T,U,true> : public T
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

	PAIR<Empty,int> p;
	std::cout << sizeof(p) << std::endl;	// 4

	PAIR<int,Empty> p2;
```

- [source 2_EBCO3  73 page](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/2_EBCO3.cpp)


---------

## function object :구조체를 함수처럼 사용할수 있으면 함수 객체라고 한다.

###  function object : operator()
- 구조체를 함수처럼 사용할수 있으면 함수 객체라고 한다.
```cpp
int Add(int a , int b){ return a+b;}
struct Plus
{
	int operator() (int a , int b){ return a+b; }
};
int main()
{
	Plus p;
	int n1 = Add(1,2); // ok
	int n2 = p(1,2);	// p.operator()(1,2)

	// a+b;   // a.operator+(b)
	// a();	  // a.operator()()    ()연산자를 호출하라
	// a(1,2); // a.operator()(1,2)
}
```

- [source 3_function_object1 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/3_function_object1.cpp)


---------

### operator()
* operator()
- 함수 객체의 장점 1. 상태를 가지는 함수
	1. 일반 함수는 동작만 있고 상태는 가질수 없다.
	1. 함수 객체는 클래스(구조체)이므로 멤버 데이터와 멤버 함수 활용 가능
```cpp
struct Plus
{
	int base;
	Plus(int a = 0) : base(a) {}
	int operator() (int a , int b){ return a+b+base; }
};
```

- [source 3_function_object2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/3_function_object2.cpp)


---------

### 인자로 함수 객체 전달시 compile time에 inline으로 치환
- 함수 객체의 장점 2.
	- 다른 함수의 인자로 전달되는 함수를 만들때
	1. 일반함수를 보내면 다시 호출시 인라인 치환되지 못한다.
        - 주소만 넘기므로 , 그 주소를 받고는 Add가 뭔지는 알수 없다.  compile time에 주소만 알고 있음. 
	1. 함수 객체를 보내면 다시 호출시 인라인 치환된다. 
		- f.operator()(1,2) 을 compile할때 할수 있다. 
		- compile time에 Plus인지를 알고 있으므로 compile time에 치환 가능하다.
- makefile의 3_function_object3에 assembly 코드 얻는 방법 있음.
    - [makefile](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/makefile)
```cpp
inline int Add(int a , int b){ return a+b;}

struct Plus
{
	inline int operator() (int a , int b){ return a+b; }
};

template<typename T> void foo(T f)
{
	int n = f(1,2);	
};

	foo(Add); 	// 함수 포인터 전달 foo( int (*f)(int, int) )
	Plus p;
	foo(p); 	// Plus 타입으로 전달 foo(Plus)
```

- [source 3_function_object3 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/3_function_object3.cpp)


---------

### lambda expression
- lambda expression = 함수 객체 + 임시 객체
	- default 생성자는 없다.
	- 복사 생성자는 있다.
- cppreference.com
	- Closure 검색해보세요.
	- Closure : 람다표현식이 만드는 임시객체를 클로져 라고 한다. 
- https://en.cppreference.com/w/cpp/language/lambda
-  lambda expression은 
    - 아래와 같이 class를 만들어 임시 객체를 자동ㅇ로 만들어준다.
```cpp
	class xx { operator()(int,int) };  
	xx();	
```
- lamdba 객체는 rvalue이다.
```cpp
	// C++11 lambda expression: 함수 객체인 임시 객체이다.
	foo( [](int a , int b){return a+b; } );

	[](int a , int b){return a+b;}(1,2); 
		// lambda임시객체(1,2)

	auto f = [](int a , int b){return a+b; }; 
	f(1,2);

	auto& a1 = [](int a , int b){return a+b; }; 		// error : rvalue 
	const auto& a2 = [](int a , int b){return a+b; }; 	// ok
	auto&& a3 = [](int a , int b){return a+b; }; 		// ok : forwarding reference
```
- 람다 표현식이 만드는 클래스는 디폴트 생성자가 없다. 
    - 디폴트 생성자 : constructor   없음.
    - 대입 생성자 : operator=       없음.  임시객체는 바로 사라지니까
    - 복사 생성자 : operator()      있음.
```cpp
	decltype(f) f2; 	// error : default 생성자 실행해야 하는데 없음.
	decltype(f) f3(f);  // ok .. 복사 생성자는 있다.
```

- [source 3_function_object4 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/3_function_object4.cpp)


---------

## unique_ptr

### smart pointer
- 스마트 포인러를 만들어봅시다.
- 핵심 : -> 와 *를 재정의하여 포인터 처럼 보이게 하는 것
- 장점 : raw pointer가 아니라 객체이므로 자동소멸 / 자동 삭제 가능하다. 
```cpp
class unique_ptr
{
	Car* obj;
public:
	unique_ptr(Car* p = 0) : obj(p) {}
	virtual ~unique_ptr() { delete obj; }

	Car* operator->(){ return obj; }
	Car& operator*(){ return *obj; }
};

int main()
{
	unique_ptr p1(new Car);
	p1->Go(); 
		// (p1.operator->())Go()
		// (p1.operator->())->Go()

	(*p1).Go();	// p1.operator*
}
```

- [source 4_unique_ptr1 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/4_unique_ptr1.cpp)


---------

### template unique_ptr & 복사 생성자 / 대입 연산자 
- p2 = p1처럼 쓰고 싶으면 , shared_ptr을 사용하라는 것이다.
```cpp
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
	unique_ptr<int> p1(new int);    // constructor call
	*p1 = 10;
	unique_ptr<int> p2 = p1; // 이렇게 하면 죽을 것임.
		// 이렇게 쓰지 못하게 하려면 복사 생성자를 못 만들게 해야 한다. 
		// p2 = p1처럼 쓰고 싶으면 , shared_ptr을 사용하라는 것이다.
}
```

- [source 4_unique_ptr2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/4_unique_ptr2.cpp)


---------

### memory 해제 함수
- free : memory만 해제
```cpp
struct Freer
{
	// free는 소멸자를 호출하지 않으므로 void* 를 사용해도 됩니다. 
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};
```

- delete : 소멸자도 호출
    - 인자로 void* 를 사용하지 못함. 
```cpp
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
```

- unique_ptr : 삭제자를 template 인수로 받음
```cpp
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
```

- [source 4_unique_ptr3 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/4_unique_ptr3.cpp)


---------

###  삭제자를 보관
```cpp
class unique_ptr
{
	T* obj;
    D d;    // 삭제자를 보관합니다.   ~소멸자에서는 삭제
```

- [source 4_unique_ptr4 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/4_unique_ptr4.cpp)


---------

###  삭제자와 type을 PAIR에 보관
- struct default_delete 가  empty class이므로 PAIR를 사용하여 memory를 절약하려는 것이다. 
```cpp
class unique_ptr
{
	// T* (m.getValue2());
    // D d; 
    PAIR<D,T*> m;
```

- [source 4_unique_ptr5 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/4_unique_ptr5.cpp)


---------

### 배열도 처리
- 아래 [] 추가
```cpp
template<typename T> struct default_delete<T[]>
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete[] p;
	}
};
class unique_ptr< T[], D >
{
    ...
    // 배열버젼에서는 []을 제공하는 것이 좋습니다.
    T& operator[](int idx)
    {
        // m.getValue2() : 보관된 포인터 꺼내기
        return m.getValue2()[idx];
    }
    ...
};

	unique_ptr<int[]> p2(new int[10]);
    p2[0] = 10;
```

- [source 4_unique_ptr7 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/4_unique_ptr7.cpp)


---------

### std로 처리
```cpp
int main()
{
    std::shared_ptr<int> sp1(new int);
    std::shared_ptr<int[]> sp1(new int[10]); // C++17부터 가능
        // C++11은 delete를 넣어야 한다. 

    std::unique_ptr<int> p1(new int);
    std::unique_ptr<int[]> p2(new int[10]);

    p1[0] = 10; // error
    *p1 = 10;   // ok
    p2[0] = 10; // ok
    *p2 = 10;   // error 배열은 꼭 배열로만 써야함.

}
```

- [source 4_unique_ptr8 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/4_unique_ptr8.cpp)


---------

### move와 forward로 변경 
- 이번 소스에서 변한 것 (2가지)
    1. 생성자가  변경 - forwarding reference 사용
        -  &&와는 std::forward<>() 
    1. unique_ptr안에 move 생성자 추가
        - T* 에 대해서 move로 처리
```cpp
template<typename T, typename U> struct PAIR : public T
{
	template<typename A , typename B>
	PAIR(A&& a, B&& b)
		: T(std::forward<A>(a)) 	// 기반 클래스 생성자 호출
		, v2(std::forward<B>(b)){}
}
template<typename T, typename D = default_delete<T> >
class unique_ptr
{
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

    // unique_ptr<int> p3 = p2;    // error 자원을 독점하기로 했기에 error
    unique_ptr<int> p4 = std::move(p2); // 되어야함.

```
- [source 6_unique_ptr9 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/6_unique_ptr9.cpp)


---------

## move

### 깊은 복사
- [source 5_move1 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move1.cpp)


---------

### rvalue 얕은 복사 + move생성자
-  
```cpp
class People
{
    // 깊은 복사로 구현한 복사 생성자
    People(const People& p) : age(p.age)
    {
        // 포인터 변수는 메모리 자체를 복사
        name  = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }

    // 임시 객체 (rvalue)인 경우 : 얕은 복사
    // foo() 임시 객체를 p로 받은 것임
    // name 자원을 이동한 것으로 "move 생성자"
    People(const People&& p) : age(p.age) , name(p.name)
    {
        p.name = nullptr;  // 자원 포기
    }
};

    People p3 = foo();
};
```

- [source 5_move2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move2.cpp)


---------

###  std::move 사용 1
```cpp
    std::string s1 = "hello";
    std::string s2 = std::move(s1);

    std::vector<int> v1 = { 1,2,3};
    std::vector<int> v2 = std::move(v1);
}
```

- [source 5_move4 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move4.cpp)


---------

###  class 생성자의 자원 할당 유무에 따른 준비 과정
- 클래스가 자원을 할당하지 않으면 - 소멸자가 없어도 된다. 
- 클래스가 자원을 할당하면 3가지가 필요하다. rule of 3 (C++98)
    - 소멸자
    - 복사생성자
    - 대입연산자
- C++11 추가로 2개 더 필요 (move) - rule of 5  (임시객체(rvalue)를 위한 복사 및 대입)
    - move 생성자
    - move 대입연산자

- move 계열 함수를 제공하지 않으면
    - 복사계열 함수가 호출된다.   &&이 없으면  const &이 다 받아준다.
```cpp
    Test() {}   // resource = new int;

    ~Test() {}
    Test(const Test& t){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(const Test& t){std::cout << __PRETTY_FUNCTION__ << std::endl;  return *this; }

    Test(Test&& t){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(Test&& t){std::cout << __PRETTY_FUNCTION__ << std::endl;  return *this; }
```

- [source 5_move5 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move5.cpp)


---------

### move생성자에서는 모든 멤버를 반드시 move로 옮기자
```cpp
    // move생성자에서는 모든 멤버를 반드시 move로 옮기자
    Test(Test&& t):data(t.data),s(std::move(t.s)){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(Test&& t)
    {
        data = std::move(t.data);
        s = std::move(t.s);
        std::cout << __PRETTY_FUNCTION__ << std::endl;  return *this; 
    }
```

- [source 5_move6 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move6.cpp)


---------

### noexcept
- noexcept 지시어 : 함수가 예외가 없음(있음)을 알리는 것
    - void foo() noexcept
    - void foo() noexcept(true)
    - void foo() noexcept(false)

- noexcept 연산자 : 표현식이 예외가 있는지 조사하는 것
    - bool b = noexcept(foo())
    - bool b = noexcept(T())
    - bool b = noexcept(T(T()))
```cpp
class Test
{
    Test(Test&& t) noexcept(   
                            std::is_nothrow_move_constructible<std::string>::value
                           ) :data(t.data),s(std::move(t.s)){std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Test& operator=(Test&& t)  noexcept (
                            std::is_nothrow_move_constructible<std::string>::value
                                        )
    {
        data = std::move(t.data);
        s = std::move(t.s);
        std::cout << __PRETTY_FUNCTION__ << std::endl;  

        return *this; 
    }
};

    Test t4 = std::move_if_noexcept(t3);
```

- move와 예외
    - move 계열 함수를 만들때는 예외가 나오지 않게 만들고 예외가 없다고 꼭 컴파일러에게 알려주자. 
    - noexcept : 예외가 없다. 
    - noexcept(true) : 예외가 없다. 
    - noexcept(false) : 예외가 있다.
- 수행하지 않는 표현식
    - sizeof(표현식)  : 표현식의 크기
    - decltype(표현식)  : 표현식의 타입
    - noexcept(표현식)  : 표현식의 예외 여부 조사  2개 이상이면 || &&
- 강력 보장
    - move는 하다가 실패하면 뒤로 되돌릴수 없어서 강력 보장을 지킬수 없다. 
    - 그러므로, stl에서는 기본적으로는 copy로 처리한다. 
    - noexcept를 넣으면 move로 처리

- [source 5_move7 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move7.cpp)


---------

###  example : swap
- move 와 알고리즘
- move에서 알아야 하는 것
    1. 클래스 만들때 move 계열 함수 2개를 만드는 법
    1. 일반 알고리즘 구현할때 move() 가 빠른 경우가 있다. 
```cpp
template <typename T> void Swap(T& a, T&b)
{
    //T tmp = a;
    //a = b;
    //b = tmp;

    T tmp = std::move_if_noexcept(a);
    a = std::move_if_noexcept(b);
    b = std::move_if_noexcept(tmp);
}
```

- [source 5_move8 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move8.cpp)


---------

###  복사 / move 생성자 관련 컴파일러의 처리 방식
1. 사용자가 복사와 move를 모두 제공하지 않으면 컴파일러가 모두 제공해준다.
    - 복사 또는 move = delete하는 경우는 컴파일러가 자동으로 만들어주지 않는다.
1. 사용자가 복사 계열 함수를 제공하면 컴파일러는 move 계열을 제공하지 않는다.

- rule of 0 : 사용자가 직접 자원을 관리하지 않으면 소멸자복사계열2개,move계열 2개를 만들 필요가 없다.
    - 컴파일러가 모두 제공
    - 내부적으로 char* 와 같이 raw pointer를 사용하지 말아라. char*가 필요하면 string을 쓰고 , array가 필요하면 vector를 사용해라. 
```cpp
class Object
{
    Test data;
public:
    Object(){}
    Object(const Object& o) : data(o.data){}
};
```

- [source 5_move9 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move9.cpp)


---------

###  std::move 사용 2
- const는 뭘해도 move안됨 
```cpp
int main()
{
    Test t1;
    Test t2 = std::move(t1); // move
        // static_cast<Test&&>(t2)

    const Test t3;
    Test t4 = std::move(t3);
        // static_cast<const Test&&>(t2)
        // const Test&&은 Test&&와 exact matching이 안되므로 
        // const Test&&은 모든 것을 다 받아줄수 있는 const Test& 으로 온다. 
        // 그래서 const는 move될수 없다. 
}
```

- [source 5_move10 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move10.cpp)


---------

### setter
-  setter 2번이 가장 좋은 방법이고  
-  1개로 해결하려면 setter 4번으로 하면 됨
```cpp
//  중요한 이야기
//  setter 2번이 가장 좋은 방법이고  
//  1개로 해결하려면 setter 4번으로 하면 됨
class Object
{
    Test data;
public:
    Object(){}
    // void setData(Test d){ data = d; }

    // setter만들기 1. const & - 항상 복사 사용
    void setData(const Test& d){ data = d; }

    // setter만들기 1. const & - 항상 복사 사용 (const 는 move될수 없다.)
    void setData(const Test& d){ data = std::move(d); }

    // setter 2. 2개 만들자
    // const & 버젼과 && 버젼 으로 2개 만들자
    void setData(const Test& d){ data = d; }
    void setData(Test&& d){ data = std::move(d); }

    // setter 3. call by value는 아주 나쁠까?
    // move가 빠르면 call by value 1개만 써서 해결해도 된다.
    void setData(Test d){ data = std::move(d); }

    // setter 4. forwarding reference
    template<typename T> void setData(T&& d)
    {
        // data = d;   // 1 무조건 복사 
        // data = std::move(d);    // 2  무조건 move
        data = std::forward<T>(d);    // 3
    }
};

int main()
{
    Object obj;
    Test data;

    obj.setData(data);  
        // setter 2. 복사 대입연산자 1회
        // setter 3. 복사 생성자 1회 , move 대입연산자 1회

    obj.setData(std::move(data)); 
        // setter 2. move 대입연산자 1회
        // setter 3. move 생성자 1회 , move 대입 1회
}
```

- [source 5_move11 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move11.cpp)


---------

###  vector push_back
- 복사는 이후에도 계속 사용한다는 의미를 가진다.
- std::move(data)는 이후에는 data는 사용하지 않겠다는 것을 의미한다.
```cpp
int main()
{
    std::vector<Test> v;
    v.reserve(10); // 메모리 미리 확보

    Test data;

    v.push_back(data);  // 복사
    v.push_back(std::move(data)); // 자원 이동
}
```

- [source 5_move12 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day4/5_move12.cpp)


---------

