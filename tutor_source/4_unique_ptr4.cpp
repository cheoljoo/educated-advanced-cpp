#include <iostream>
#include <memory>

template<typename T> struct default_delete
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete p;
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


template<typename T, typename D = default_delete<T> >
class unique_ptr
{
	T* obj;
	D  d;    // �����ڸ� �����մϴ�.
public:
	inline unique_ptr(T* p = 0, const D& del = D() ) 
		: obj(p), d(del) {}
	inline ~unique_ptr()
	{
		d(obj); 
	}

	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};

int main()
{
	unique_ptr<int>  p1(new int);

	unique_ptr<int, Freer> p2((int*)malloc(100));

	// error.����ǥ������ ����� Ÿ���� �ƴ϶� ��ü�̴�.
	//unique_ptr<int, [](int*) {free(p); } > p2((int*)malloc(100));


	//unique_ptr<int, decltype([](int*) {free(p); }) > p2((int*)malloc(100));

	// �����ڷ� ����� ����ǥ������ ���� auto ������ ��´�.
	auto del = [](void* p) { free(p);
				std::cout << "lambda" << std::endl; };

	unique_ptr<int, decltype(del)> p3(new int, del);





//	foo(a);// �Լ� ���ڴ� ��ü�� �ʿ�
//	list<int>; // ���ø� ���ڴ� ����Ÿ Ÿ��
}



