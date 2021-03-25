#define _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING

#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

template<typename T, typename Ax = std::allocator<T> > class vector
{
	T* buff;
	int size;
	int capacity;
	Ax  ax; // 메모리 할당기
public:
	vector(int sz, const T& value = T()) : size(sz), capacity(sz)
	{
		buff = ax.allocate(sz);

		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; i++)
			{
				std::allocator_traits<Ax>::construct(ax, &buff[i], value);
				++cnt;
			}
		}
		catch (...)
		{
			for (int i = 0; i < cnt; i++)
				std::allocator_traits<Ax>::destroy(ax, &buff[i]);

			ax.deallocate(buff, size);

			buff = nullptr;
			size = 0;
			capacity = 0;
		}
	}
	~vector()
	{
		if (buff)
		{
			for (int i = 0; i < size; i++)
				std::allocator_traits<Ax>::destroy(ax, &buff[i]);

			ax.deallocate(buff, size);
			buff = nullptr;
			size = 0;
			capacity = 0;
		}
	}

	void resize(std::size_t newSize, const T& value = T())
	{
		if (newSize > capacity)
		{
			// 메모리 할당 필요

			// 아래 코드 문제점
			// 1. T 타입에 디폴트 생성자가 필요 하다
			// 2. 생성자가 호출되는 표현이므로, 각요소의 자원도 할당됨..
			//    하지만, 결국 기존 버퍼의 내용을 덮어 쓰게된다. 
			// T* temp = new T[newSize];

			// T* temp = static_cast<T*>(operator new(sizeof(T) * newSize)); // 이렇게 해야 한다!
			
			T* temp = ax.allocate(newSize);

			// 기존 버퍼의 객체는 신규 버퍼로 이동한다.
			for (int i = 0; i < size; i++)
			{
				//new(&temp[i]) T(buff[i]);  // 복사 생성자
				//new(&temp[i]) T(std::move(buff[i]));  // move 생성자
				//new(&temp[i]) T(std::move_if_noexcept(buff[i]));  

				std::allocator_traits<Ax>::construct(ax, &temp[i], std::move_if_noexcept(buff[i]));
			}

			// 새로운 공간은 resize 인자로 전달된 객체로 초기화
			for (int i = size; i < newSize; i++)
			{
				std::allocator_traits<Ax>::construct(ax, &temp[i], value);
			}
			size = newSize;
			capacity = newSize;

		}
		else
		{
			// 메모리할당 필요 없다.
		}

	}
};




int main()
{
	vector<Point> v(10, Point(1, 2));

	//v.resize(15, Point(0, 0));
	v.resize(7, Point(0, 0));
}









// 내일 최종 평가 : swmooc.lge.com  에서 4시정도 부터 진행합니다.
