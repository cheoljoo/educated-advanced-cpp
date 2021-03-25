#include <thread>
#include <memory>
#include <iostream>

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << " bytes" << std::endl;
	return malloc(sz);
}

class Point
{
	int x, y;
public:
	Point(int a, int b) {  }
};

// std::make_shared 의 원리
template<typename T, typename ... Ts> 
std::shared_ptr<T> make_shared(Ts&& ... args )
{
//	T* p = new T( std::forward<Ts>(args)... );

	// 위처럼 하면 객체만 메모리 할당 됩니다.
	// 객체 + 관리 객체를 한번에 할당하는데, 생성자호출이 되지 않게 해야 합니다.
	void* p = operator new(sizeof(T) + sizeof(관리객체타입));

	// 객체와 관리 객체의 생성자 호출.
	new (p) T(std::forward<Ts>(args)...); // 완벽한 전달로 인자 전달

	// 관리 객체 생성자 호출
	new ((char*)p + sizeof(T)) 관리객체타입;

	// shared_ptr 만들어 반환
	std::shared_ptr<T> sp;
	sp.reset(p, (char*)p + sizeof(T));
	return sp;
}


int main()
{
	// 아래 코드는 동적 메모리 할당이 몇번 발생할까요 ?
	//std::shared_ptr<Point> sp(new Point(1, 2));

	// 아래 코드는 
	// sizeof(Point) + sizeof(관리객체) 를 한번에 메모리 할당하게 됩니다
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);
}







