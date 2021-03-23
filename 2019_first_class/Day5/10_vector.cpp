/* base Day2 1_new4
-  resize를 만들 것임 . 
*/

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
#include <type_traits>
#include <string>

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
    ~vector()
    {
        for(int i=0;i<size;i++){
            buff[i].~T();
        }
        operator delete(buff);
    }
    void resize(size_t newSize,const T& value = T())
    {
        if(capacity > newSize){
            // 메모리 재할당이 필요 없다. 
            if(newSize < size){ // size가 줄어들때
                for(int i = size-1 ; i>= newSize; i--)
                    buff[i].~T();
            }
            else {  // size가 증가할때
                for(int i= size ; i < newSize; i++)
                    //new(&buff[i]) T;   // default 생성자 인데 이보다 복사 생성자가 좋은 코드 이다. 
                    new(&buff[i]) T(value); // 복사 생성자
            }
        } else {
            // 메모리 재할당이 필요하다. 
            // 1. 메모리만 먼저 할당
            T* temp = static_cast<T*>(operator new(sizeof(T) * newSize));

            // 2. 기존 버퍼 내용을 가져오기
            if(std::is_trivially_copy_constructible_v<T>) {
                memcpy(temp,buff,sizeof(T)*size);
            }
            else {
                for(int i= 0;i<size;i++){
                    //temp[i] = buff[i]; // 대입연산자
                    //new(&temp[i]) T(buff[i]);  // 복사 생성자
                    //new(&temp[i]) T(std::move(buff[i]));  // move 생성자
                    new(&temp[i]) T(std::move_if_noexcept(buff[i]));  // move 생성자
                }
            }

            // 새로 추가된 요소는 디폴트 (또는 인자로 받은 객체로 복사 생성)
            for(int i=size;i<newSize;i++){
                new(&temp[i]) T(value);
            }

            // 기존 버퍼 제거
            for(int i=0;i<size;i++){
                buff[i].~T();
            }
            operator delete(buff);

            // 새로운 메모리를 버퍼에 연결
            buff = temp;
            size = newSize;
            capacity = newSize;

        }
    }
};


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
    //Point p(0,0);
    //vector<Point> v(10,p); 

    vector<int> v(10);
    v.resize(7);    // cap : 10 , size : 7
    v.resize(9);     
    v.resize(21);    
}
