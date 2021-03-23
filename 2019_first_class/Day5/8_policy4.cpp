/*
- 
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
    //ax.construct(&p1[0],1,2);
    //ax.construct(&p1[1]);

    //ax.destroy(&p1[0]);
    //ax.destroy(&p1[1]);

	std::allocator_traits<Mallocator<Point>>::construct(ax, &p1[0],1,2);
	std::allocator_traits<Mallocator<Point>>::destroy(ax,&p1[0]);
		// traits는 안에 Mallocator에 destroy가 있는지를 찾아준다. 

    ax.deallocate(p1,2);

}
