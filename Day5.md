

# Day5

- Modern C++ Design 책 - 안드레이 알렉산드레스큐
    - visitor pattern  -> C++17 표준에 들어옴.

------------

- 가능하면 const noexcept 을 많은 곳에 붙이자.
- static_assert : compile time에 진행하므로 많아도 좋다. 

## checked delete

###  checked delete
- 클래스 전방선언
    -  완전한 선언이 없어도 포인터 변수는 만들수 있다. 
    -  불완전한 타입 (incomplete type) : 소멸자가 불리지 않는다. 
- 불완전한 type을 사용할때는 그냥 delete하면 안된다.
    - 그래서 check하고 delete하자
    - sizeof(A); A가 complete type일때만 크기를 구할수 있다. 이를 이용하여 check
- 안드로이드 소스의 예전 버전에서 볼수 있던 코드
    - ```enum{ type_must_be_complete = sizeof(Test) };```   최적화로 없애지 못하게
```cpp
void foo(Test* p)
{
    //sizeof(Test);   // complete 타입만 크기를 구할수 있다.
    static_assert( sizeof(Test) > 0 , "error, delete incomplete type");
    delete p;
}
```

- [source 1_checked_delete  37 page ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/1_checked_delete.cpp)


---------

## explicit

###  직접 초기화
- explicit 생성자 : 복사 초기화를 사용할 수 없다. 
```cpp
public:
    explicit Vector(int sz){}

int main()
{
    Vector v1(10);      // direct initialization : default 생성자
    Vector v2 = 10;     // error : explicit가 아니면 성공 : copy initialization : 복사 생성자
    Vector v3{10};      // direct

    foo(v1);    // ok
    foo(10);    // 복사 초기화가 일어나는 것으로 안되게 하는게 좋다.
                // 생성자 만들때 explicit 사용
                // error : explicit붙일때
}
```

- [source 2_explicit ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/2_explicit.cpp)


---------

###  container에 따른 explicit 유무
```cpp
int main()
{
    // string의 생성자는 explicit가 아니다.
    std::string s1("hello");    // explicit이면 이것이 error
    std::string s2 = "hello";   //  복사 초기화 // ok
    // foo("hello"); // explicit생성자라면 error

    // vector는 생성자가 explitit
    std::vector<int> v1(10);    // 초기값이 아닌 크기. 10개짜리 vector
    std::vector<int> v2 = 10; // error
    std::vector<int> v3 {10 }; // 1개짜리 vector인데 초기값이 10
    std::vector<int> v4 = { 10} ;  // ok
 
    // c++ 표준 스마트 포인터는 모두 explicit
    std::unique_ptr<int> p1(new int);
    std::unique_ptr<int> p2 = new int;  // error
}
```

- [source 2_explicit2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/2_explicit2.cpp)


---------

### initializer_list : 메모리에 연속적으로 놓은 동일 타입이 객체를 관리하는 도구
- stack에 연속적으로 놓여직 됨. VC++는 시작과 끝 주소만을 가짐
```cpp
void foo(std::initializer_list<int> e)
{
}
int main()
{
    // initializer_list : 메모리에 연속적으로 놓은 동일 타입이 객체를 관리하는 도구
    //          stack에 연속적으로 놓여직 됨. VC++는 시작과 끝 주소만을 가짐
    std::initializer_list<int> s = {1,2,3,4,5,6,7};

    foo(s);
    foo({1,2,3,4,5,6,7});  // ok : 이게 가능하다.  이것때문에 initializer_list를 만듦

    auto p = s.begin();
    std::cout << *p << std::endl;
}
```

- [source 2_explicit3 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/2_explicit3.cpp)


---------

### initializer_list 생성자가 없으면 , 복사 생성자로  (갯수가 같을때만) 
```cpp
class Vector
{
public:
    explicit Vector(int size){}
    explicit Vector(int size , int value)    // 1
    {
        cout << "1" << endl;
    }
    Vector(initializer_list<int> s) // 2 
    {
        cout << "2" << endl;
    }
};

int main()
{
    Vector v4 = 10 ; // error
    Vector v5 = {10} ; // ok

    Vector v1(10,3);    // 10개를 3으로 초기화
    Vector v2{10,3};    // 2번생성자가 없으면 1번 생성자으로 간다
    Vector v2{10,3,1,2,3,4};
}
```

- [source 2_explicit4 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/2_explicit4.cpp)


---------

## make

### 안정성
- 아래 한줄은 안전할까요? 아래처럼 실행되면 문제가 발생할수 있다.
    1. new Point(1,2)
    1. foo() => 여기서 예외가 나오면 1의 코드가 메모리 누수
    1. unique_ptr 생성
```cpp
    goo( unique_ptr<Point>(new Point(1,2)) , foo()  );
        // goo 안의 2개의 함수는 어떤게 먼저 수행될지 모름
        // Point  -> foo -> unique_ptr을 하는데 , foo에서 문제 발생시 자원이 안전하지 않다. 
```

- [source 3_make ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/3_make.cpp)


---------

### make_unique
```cpp
// unique_ptr을 만드는 함수
template<typename T,typename ... ARGS>
std::unique_ptr<T> make_unique(ARGS&& ... args)
{
    return std::unique_ptr<T>(new T(std::forward<ARGS>(args)...));
}
```

- [source 3_make2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/3_make2.cpp)


---------

## coercion
- coercion
    - int가 double로 변환되면 , Point<int>도 Point<double>로 변환되어야 한다. 

### generic 복사생성자
```cpp
template <typename T>
class Point
{
    T x, y;
public:
    Point(T a=T(), T b=T()) : x(a),y(b){}

    // 복사 생성자의 구현을 밖으로 뽑아보려함.
    Point(const Point<U>& p) : x(p.x) , y(p.y);

    template<typename U> friend class Point; //  모든 Point들은 friend
};
// member template의 외부 구현 
// 클래스 템플릿의 멤버 템플릿의 외부 구현
template<typename T> template<typename U>
Point<T>::Point(const Point<U>& p) : x(p.x) , y(p.y) 
{
}
int main()
{
    Point<int>  p1(3  , 4); // 위의 생성자를 부름. 일반 생성자
    Point<int> p2 = p1;     // 복사 생성자 ,  computer가 만들어줌

    Point<double> p3 = p1;  // error : 다른 type에는 복사 생성자가 있을수 없다. 
}
```

- [source 4_coercion2  43 page ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/4_coercion2.cpp)


---------

## using
-  c++14부터 아래 코드를 제공합니다. 

### is_poiner_v remove_pointer_t 
- using 문법
```cpp
template<typename T> using remove_pointer_t =  typename std::remove_pointer<T>::type;
```

- variable template 이라는 문법 
```cpp
template<typename T> bool is_pointer_v = std::is_pointer<T>::value;
```

- example
```cpp
template<typename T>
void foo(T a)
{
    // bool b = std::is_pointer<T>::value;
    bool b = is_pointer_v<T>::value;

    // typename std::remove_pointer<T>::type t;
    remove_pointer_t<T> t;
}
int main()
{
    int n;
    foo(&n);
}
```

- [source 5_using ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/5_using.cpp)


---------

### SFINAE ( enable_if_t )
- 원본 
```cpp
template<typename T>
typename std::enable_if<  std::is_pointer<T>::value , int > :: type
foo(T a )
{
}
```

- 위코드를 _t  _v 버젼을 사용해서 변경해 보세요.
1. 함수 반환 타입을 이용한 SNINAE : _t
```cpp
template<typename T>
std::enable_if_t<  std::is_pointer_v<T>, int >
foo(T a )
{
    return 0;
}
```

1. 함수 인자를 사용한 SFINAE - value : _v
```cpp
template<typename T>
int 
goo(T a , std::enable_if_t<  std::is_pointer_v<T>, int > = 0)
{
    return 0;
}
```

1. template 인자를 사용한 SFINAE
    - template의 인자로 int 도 받을수 있다.
```cpp
template<typename T, 
    std::enable_if_t<  std::is_pointer_v<T>, int > = 0
        >
int 
hoo(T a)
{
    return 0;
}
```

- [source 5_using2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/5_using2.cpp)


---------

## bind

### bind : N항의 함수 인자를 고정해서 M(<N)항의 함수를 만드는 도구
```cpp
#include <functional>
using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
    printf("%d %d %d %d\n",a,b,c,d);
}

int main()
{
    foo(1,2,3,4);
    // bind : N항의 함수 인자를 고정해서 M(<N)항의 함수를 만드는 도구
    std::bind(&foo, 10 , _1 , 3, _2)(5,7); // 10,5,30,7
    std::bind(&foo, 10 , 5 , 3, 7)(); // 10,5,30,7
    std::bind(&foo, _3 , 7 , _1, _2)(5,3,2); //  2,7,5,3
}
```

- [source 6_bind ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/6_bind.cpp)


---------

### 인자의 수를 변경 가능
```cpp
#include <functional>
using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
    printf("%d %d %d %d\n",a,b,c,d);
}

int main()
{
    void(*f1)(int); // 인자가 한개인 함수 주소만 담을수 있다.

    std::function<void(int)> f;
    f = std::bind(&foo, _1 , 0,0,0);;
    f(10);  // 10 ,0,0,0
}
```

- [source 6_bind2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/6_bind2.cpp)


---------

### bind는 인자를 넘길때 기본이 copy
- block등을 빠져나갈대 소멸되어 dangling pointer를 만들수 있기 때문
- 꼭 필요한 경우 std::ref 이용
```cpp
        f = std::bind(&foo, _1, n); // n이 아니라 n의 값을 고정(보관)
        f = std::bind(&foo, _1, std::ref(n)); // n이 아니라 n의 값을 고정(보관)
```

- [source 6_bind3 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/6_bind3.cpp)


---------

### example : Button
```cpp
class Button
{
    std::function<void()> handler;  // 선언은 인자 없게 했지만, bind 만 있으면 인자 늘릴수 있다. 
    void Click() { handler(); }
};
void goo() { std::cout << "goo" << std::endl; }
void hoo(int id) { std::cout << "hoo : " << id << std::endl; }
int main()
{
    Button b1,b2,b3;
    b1.handler = []() { std::cout << "Dialog Close" << std::endl; };
    b2.handler = &goo;
    b3.handler = std::bind(&hoo,2);
    b1.Click(); b2.Click(); b3.Click();
}
```

- [source 6_bind4 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/6_bind4.cpp)


---------

## reference wrapper
- C++ reference(참조) : 개념적으로 const 이다.  참조가 이동하지 않고 값을 복사하는 것이다. 
- [source 7_reference_wrapper ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/7_reference_wrapper.cpp)

### reference_wrapper: 이동가능한 참조 - 변환연산자 : operator T&()
- 변환연산자 : operator T&() 정의 필요
- 참조끼리 대입시 참조가 이동
```cpp
template<typename T> class reference_wrapper
{
    T* ptr;
public:
    reference_wrapper(T& p){ ptr = &p; }
    
    // 변환연산자: 반환 타입을 표기하지 않는 특징이 있다.
    // 객체가 다른 타입으로 변환되기 위해 필요
    operator T&() { return *ptr; }
    T& get() const{ return *ptr; }
};

main(){
    int n1 = 10;
    int n2 = 20;

    std::reference_wrapper<int> r1 = n1;
    std::reference_wrapper<int> r2 = n2;


    r2 = r1; // 이 한줄의 의미를 잘 생각해보세요.
    r2.get() = 30;

    std::cout << n1 << std::endl; //30
    std::cout << n2 << std::endl; //20
    std::cout << r1 << std::endl; //30
    std::cout << r2 << std::endl; //30
}
```

- [source 7_reference_wrapper2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/7_reference_wrapper2.cpp)


---------

### reference_wrapper의 helper 함수 : valuleForwarding
-  object generator
    - reference_wrapper를 만들어준느 헬퍼함수
    - 클래스 템플릿을 직접 만들게 하지 말고 함수 템플릿으로 만들게 하자.
```cpp
// 아래 함수가 bind처럼 인자를 값으로 받고 있다.  
template<typename F, typename T>
void valueForwarding(F f, T arg)
{
    f(arg);
}

template <typename T>
reference_wrapper<T> ref(T* obj)
{
    return reference_wrapper<T>(obj);
}

int main()
{
    int x = 0;
    valueForwarding(&foo,reference_wrapper<int>(x));    // ok : reference_wrapper의 임시객체
    valueForwarding(&foo,ref(x));    // ok : reference_wrapper의 helper사용
    std::cout << x << std::endl;    // 100
}
```

- [source 7_reference_wrapper3 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/7_reference_wrapper3.cpp)


---------

## Policy Clone
- template인자로 동기화 정책을 받자
    - 단위 전략 design (policy based design)
- webkit 소스 "source/wrf/wrf/nolock.h" 

### template 인자로 policy 결정
-  
```cpp
template<typename T , typename ThreadModel = nolock> class List
{
    ThreadModel tm;
public:
    void push_front(const T& a)
    {
        tm.lock();
        //....
        tm.unlock();
    }
};

List<int,nolock> s;    //  전역 변수.  멀티쓰레드에 안전하지 않다. 
```

- [source 8_policy 183 page ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/8_policy.cpp)


---------

### allocator  (cppreference.com)
- cppreference.com allocator 찾아봐라
    - Example을 가져와서 destroy만 추가시켰다.
    - traits에서 member를 찾아서 destroy가 있으면 그것을 찾아 호출 한다. 
```cpp
struct Point
{
    int x,y;
    Point(int a=0,int b=0){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Point(){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

// copy example in cpprefrence.com
template <class T>
struct Mallocator {
  typedef T value_type;
  Mallocator() = default;
  template <class U> constexpr Mallocator(const Mallocator<U>&) noexcept {}
  [[nodiscard]] T* allocate(std::size_t n) {
    if(n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
    if(auto p = static_cast<T*>(std::malloc(n*sizeof(T)))) return p;
    throw std::bad_alloc();
  }
  void deallocate(T* p, std::size_t) noexcept { std::free(p); }

  void destroy(T* p)
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
	p->~T();
  };
};
template <class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) { return false; }

int main()
{
    Mallocator<Point> ax;
    Point* p1 = ax.allocate(2);     // 메모리만 할당함 

	std::allocator_traits<Mallocator<Point>>::construct(ax, &p1[0],1,2);
	std::allocator_traits<Mallocator<Point>>::destroy(ax,&p1[0]);
		// traits는 안에 Mallocator에 destroy가 있는지를 찾아준다. 

    ax.deallocate(p1,2);
}
```

- [source 8_policy2 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/8_policy2.cpp)


---------

### allocator rebind
- why? : List에서는 <int> 이지만 실제로는 int를 포함하는 Node를 할당해야 한다. 그런데, Node는 외부에서는 모르는 것이므로 Mallocator<Node> 라고 template 인자로 넣어줄수 없다. 
- rebind를 이용하여 data가 가 아닌 Node size로 alloc을 해야함.
    - Mallocator<int> -> Mallocator<Node>
```cpp
template <class T>
struct Mallocator {
    
    ...

  // 아래 코드가 Policy Clone이름을 가진 기법이다.
  template<typename U>
      struct rebind
      {
          typedef Mallocator<U> other;
      };
};

// List 
template<typename T, typename Ax = std::allocator<T>>
class List
{
    struct Node
    {
        T data;
        Node *next,*prev;
    };
    typename Ax::template rebind<Node>::other ax;    // Mallocator<Node> 
        // 앞의 typename은 Ax안의 other가 type (값이 아님)
        // rebind<  <를 해석하기 위해서 그 앞에 template
public:
    void push_front(const T& a)
    {
        // 메모리 할당이 필요합니다.
    }
};

int main()
{
    List<int,Mallocator<int>> s;
    s.push_front(10);

}
```

- [source 8_policy5  184 page ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/8_policy5.cpp)


---------

### policy Clone for allocator (ex. List<int> with Node)
```cpp
template<typename T> struct MyAlloc {};
template<typename T,        // type
        int N,              // 정수
        template<typename> class AT>    // template (틀)
class Test
{
    AT<T> ax;
};

Test<int,10, MyAlloc> t;

template<typename T, template<typename> class AT> class List    // AT는 template자리
{
    struct Node {};
    AT<Node> ax;    // MyAlloc<Node> ax;
};

int main()
{
    List<int,MyAlloc> s;

}
```

- [source 8_policy6 ](https://github.com/cheoljoo/educated-advanced-cpp/blob/master/Day5/8_policy6.cpp)


---------

