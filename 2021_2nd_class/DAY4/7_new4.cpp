#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz) : size(sz), capacity(sz)
	{
		buff = new T[sz];
	}
	~vector() {}
};
int main()
{
	vector<int> v(10);

}