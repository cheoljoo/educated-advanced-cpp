#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// "Generic Container" ��� �̸��� "C++ IDioms"
// �����̳� ����� Ÿ���� ������ �ϴ� ������ �ּ�ȭ �϶�!!!
// ����Ʈ �����ڰ� ��� �����̳� ������ �־�� �Ѵ�.

// �Ʒ� vector�� ��� Ÿ���� �ּ��� "���� ������"�� ������ �ȴ�.
template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, const T& value = T()) : size(sz), capacity(sz)
	{
		// �Ʒ�ó�� ����� ����Ʈ �����ڰ� �ִ� Ÿ�Ը� �����Ҽ� �ֽ��ϴ�.
		// buff = new T[sz];

		// 1. �޸𸮸� �Ҵ�
		buff = static_cast<T*>(operator new(sizeof(T)*sz));

		// 2. ������ ȣ��
		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; i++)
			{
				// new(&buff[i]) T; // ����Ʈ ������ ȣ��
				new(&buff[i]) T(value); // ok.. ���� ������ ���
				++cnt;
			}
		}
		catch (...)
		{	
			// ������ȣ�⿡ ������ ��ü�� �Ҹ��ڸ� ȣ���ؾ� �Ѵ�
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