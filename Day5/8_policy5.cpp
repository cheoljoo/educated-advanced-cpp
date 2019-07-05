/* 184 page : rebind
- List에서는 <int> 이지만
실제로는 int를 포함하는 Node를 할당해야 한다. 그런데, Node는 외부에서는 모르는 것이므로
Mallocator<Node> 라고 template 인자로 넣어줄수 없다. 
*/

#include <iostream>
#include <vector>
//using namespace std;

/*
- cppreference.com allocator 찾아봐라
Example을 가져와서 destroy만 추가시켰다.
traits에서 member를 찾아서 destroy가 있으면 그것을 찾아 호출 한다. 
*/

struct Point
{
    int x,y;
    Point(int a=0,int b=0){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Point(){ std::cout << __PRETTY_FUNCTION__ << std::endl; }
};


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


  // 아래 코드가 Policy Clone이름을 가진 기법이다.
  template<typename U>
      struct rebind
      {
          typedef Mallocator<U> other;
      };
};
template <class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) { return false; }



// List 
template<typename T, typename Ax = std::allocator<T>>
class List
{
    struct Node
    {
        T data;
        Node *next,*prev;
    };
    //Ax ax;      // Mallocator<int> ax;
                // int가 아닌 Node이 할당기가 있어야 한다. 
    // Mallocator<Node> ax;
    //Mallocator<int>::rebind<Node>::other ax;    // Mallocator<Node>
    
    typename Ax::template rebind<Node>::other ax;    // Mallocator<Node> 
        // reference.cpp참조 
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
