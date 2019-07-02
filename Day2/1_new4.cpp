/*  1_new4.cpp   : 103 page
- vector를 만들어보자
    - buff = new T[z];와 같이 하지 말자 T에 대한 default constructor가 꼭 있어야 한다.
    - 메모리 할당자와 생성자를 분리하자.
- C++ Programming Language : C++ 창시자 책 (stroustrub)
	- STL 의 내부를 보여준다.
*/

/*
- https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h
```cpp
template<typename TYPE>
typename std::enable_if<!traits<TYPE>::has_trivial_copy>::type
inline
copy_type(TYPE* d, const TYPE* s, size_t n) {
    while (n > 0) {
        n--;
        new(d) TYPE(*s);	// <== 생성자만 호출
        d++, s++;
    }
}
```
*/


#include <iostream>
#include <vector>
#include <memory>

template <typename T> class vector
{
    T* buff;
    int size;
    int capacity;
public:
    vector(int sz, T value=T()) : size(sz),capacity(sz)
    {
        // buff = new T[sz];   // T의 default 생성자가 있어야 한다. 
                            // 103 page에서 이렇게 하지 말라는 것이다. 

        // 1. 메모리 먼저 할당
        buff = static_cast<T*>(operator new(sizeof(T) * size));

        // 2. 생성자 호출
        try
        {
            // buff ~ buff+10의 공간에 있는 객체에
            // value를 사용해서 복사 생성자 호출
            // cppreference.com에서 uninitialized_fill_n 함수 검색
			// #include <memory>
            //    Possible implementation을 보면 아래 코드와 같다. 
            std::uninitialized_fill_n(buff,10,value);
        } catch(...){
            operator delete(buff);
        }
    }
};

/*
template <typename T> class vector
{
    T* buff;
    int size;
    int capacity;
public:
    vector(int sz, T value=T()) : size(sz),capacity(sz)
    {
        // buff = new T[sz];   // T의 default 생성자가 있어야 한다. 
                            // 103 page에서 이렇게 하지 말라는 것이다. 

        // 1. 메모리 먼저 할당
        buff = static_cast<T*>(operator new(sizeof(T) * size));

        // 2. 생성자 호출
        int cnt = 0;
        try
        {
            for(;cnt<size;cnt++){
                // new(&buff[cnt]) T; // default constructor 호출
                new(&buff[cnt]) T(value); // 복사 생성자 호출
            }
        } catch(...)
        {
            // 복사 생성자 호출중 예외가 발생하면
            // 생성이 완료된 객체는 소멸자 호출
            for(int i=0;i<cnt;i++)
                buff[i].~T();

            // 메모리 해지
            operator delete(buff);

            // 발생된 예외를 밖으로 전달
            throw;
        }
    }
};
*/

class Point
{
    int x, y;
public:
    Point(int a , int b) : x(a),y(b)
    {
        std::cout << "Point()" << std::endl;
    }
};

int main()
{
    Point p(0,0);
    vector<Point> v(10,p); 
}
