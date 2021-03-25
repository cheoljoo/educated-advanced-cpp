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
		std::cout << sz << "���� �޸� �Ҵ�" << std::endl;
		return static_cast<T*>(malloc(sizeof(T)* sz));
	}
	void deallocate(T* p, std::size_t sz)
	{
		std::cout << sz << "���� �޸� ����" << std::endl;
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

	// ax �� construct �� ������ ���, ������ ����Ʈ ���� 
	std::allocator_traits<LogAlloc<Point>>::construct(ax, p1, 1, 2);
	std::allocator_traits<LogAlloc<Point>>::destroy(ax, p1);

	ax.deallocate(p1, 1);		
}


