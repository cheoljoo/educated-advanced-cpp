#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// "Generic Container" 라는 이름의 "C++ IDioms"
// 컨테이너 설계시 타입이 가져야 하는 조건을 최소화 하라!!!
// 디폴트 생성자가 없어도 컨테이너 담을수 있어야 한다.

// 아래 vector에 담는 타입은 최소한 "복사 생성자"만 있으면 된다.
template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, const T& value = T()) : size(sz), capacity(sz)
	{
		// 아래처럼 만들면 디폴트 생성자가 있는 타입만 저장할수 있습니다.
		// buff = new T[sz];

		// 1. 메모리만 할당
		buff = static_cast<T*>(operator new(sizeof(T)*sz));

		// 2. 생성자 호출
		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; i++)
			{
				// new(&buff[i]) T; // 디폴트 생성자 호출
				new(&buff[i]) T(value); // ok.. 복사 생성자 사용
				++cnt;
			}
		}
		catch (...)
		{	
			// 생성자호출에 성공한 객체는 소멸자를 호출해야 한다
			for (int i = 0; i < cnt; i++)
				buff[i].~T();

			operator delete(buff);
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
				buff[i].~T();

			operator delete(buff);
			buff = nullptr;
			size = 0;
			capacity = 0;
		}
	}
};
int main()
{
//	Point pt(1, 2);
//	vector<Point> v(10, pt);
	vector<Point> v(10, Point(1,2) );

}