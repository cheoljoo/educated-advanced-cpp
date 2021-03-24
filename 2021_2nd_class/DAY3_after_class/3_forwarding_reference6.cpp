#include <vector>
#include <iostream>

template<typename T> class Vector
{
	T* buff;
public:
	Vector(std::size_t sz, T value)
	{
		buff = new T[sz];
	}
	T& operator[](int idx) { return buff[idx]; }
};
// bool 을 보관하는 Vector 는 specialization 버전 사용
template<> class Vector<bool>
{
	int* buff;
public:
	Vector(std::size_t sz,  bool value)
	{
		buff = new int[sz/32 + 1];
	}
	// [] 연산자는 비트를 반환할수 있어야 합니다.
	// Bit 반환을 위한 Proxy
	struct BitProxy
	{
		int* buff;
		int idx;

		BitProxy(int* buff, int idx) : buff(buff), idx(idx) {}

		BitProxy& operator=(bool b)
		{
			printf("%p 버퍼의 %d번째를 %d 로 채우기\n", buff, idx, b);
			return *this;
		}
		
		operator bool()
		{
			std::cout << "buff 의 idx 를 조사해서 결과 반환" << std::endl;

			return true;
		}
	};	   

	BitProxy operator[](int idx) { return BitProxy(buff, idx); }
};
int main()
{
//	Vector<int>  v1(10, 3);
//	Vector<bool> v2(10, false);

	std::vector<bool> v2(10, false);

	v2[0] = false;
	bool b = v2[0];

//	auto& r1 = v1[0]; // ok.    v1[0] 은 임시객체 아님.
//	auto& r2 = v2[0]; // error. v2[0] 은 임시객체 반환.
	auto&& r2 = v2[0]; // ok.. forwarding reference

	auto a = v2[0];
	std::cout << typeid(a).name() << std::endl;
	
}




