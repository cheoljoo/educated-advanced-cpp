#include <vector>
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

template<typename T> struct LogAlloc
{
	T* allocate(std::size_t sz)
	{
		std::cout << sz << "개의 메모리 할당" << std::endl;
		return static_cast<T*>(malloc(sizeof(T)* sz));
	}
	void deallocate(T* p, std::size_t sz)
	{
		std::cout << sz << "개의 메모리 해지" << std::endl;
		free(p);
	}

	using value_type = T;
	LogAlloc() = default;
	template<typename U> LogAlloc(const LogAlloc<U>&) {}
};

int main()
{
	LogAlloc<Point> ax;

	Point* p1 = ax.allocate(1); 

//	ax.construct(p1, 1, 2);		
//	ax.destroy(p1);				

	// ax 에 construct 가 있으면 사용, 없으면 디폴트 제공 
	std::allocator_traits<LogAlloc<Point>>::construct(ax, p1, 1, 2);
	std::allocator_traits<LogAlloc<Point>>::destroy(ax, p1);

	ax.deallocate(p1, 1);		
}


