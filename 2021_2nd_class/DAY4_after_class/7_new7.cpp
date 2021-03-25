#include <vector>
#include <iostream>

// 사용자 정의 allocator는 4개의 함수를 만들어야 합니다.
// "인터페이스등으로 정의되어 있지 않고, 표준 문서에 문서화 되어 있습니다."

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
	void destroy(T* p) { p->~T(); }

	template<typename ... Ts>
	void construct(T* p, Ts&& ... args)
	{
		new(p) T( std::forward<Ts>(args)...);
	}

	// 위 4개의 함수외에 아래 3개가 더 필요 합니다
	using value_type = T;
	LogAlloc() = default;
	template<typename U> LogAlloc(const LogAlloc<U>&) {}
};

int main()
{
	std::vector<int, LogAlloc<int> > v;

	std::cout << "---------------" << std::endl;
	v.resize(10);
	std::cout << "---------------" << std::endl;
	//v.resize(5);
	v.resize(15);
	std::cout << "---------------" << std::endl;
}