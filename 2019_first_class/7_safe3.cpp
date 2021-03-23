//  7_예외안전성3 - 59 page  (책에 있는 코드: copy and swap)
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <exception>
#include <stdexcept>
//using namespace std;

class String
{
    char* buff;
public:
    // 이것은 얕은 복사가 되어서 , s1=s2를 하면 주소만 copy되는 것이다. 
    String(const char* s)
    {
        buff = new char[strlen(s)+1];
        strcpy(buff,s);
    }
    ~String(){ delete[] buff; }


    /*
    // 깊은 복사로 구현한 대입 연산자
    String& operator=(const String& s)
    {
        // 자신과 대입할 경우 (s1 = s1)
        if(&s == this) return *this;

        // 자신 버퍼 제거
        delete[] buff;

        // 새로운 buf 할당
        buff = new char[strlen(s.buff)+1];      // 메모리 부족시 예외 발생  : try catch를 해주어도 복구할 방법이 없다. 
        strcpy(buff,s.buff);
        return *this;
    }
    */

    String(const String& s)
    {
        buff = new char[strlen(s.buff)+1];      // 여기서 fail이 나면 그 이후는 수행을 하지 않는다. 그러나, 나는 안전한다. 
        strcpy(buff,s.buff);
    }
    void swap(String& s)
    {
        char* temp = s.buff;
        s.buff = buff;
        buff = temp;
    }


    // 깊은 복사로 구현한 대입 연산자
    // ** exception safety를 아는 사람들은 대입을 해도 이렇게 짜야 한다.  **
    String& operator=(const String& s)
    {
        // 자신과 대입할 경우 (s1 = s1)
        if(&s == this) return *this;

        // s의 복사본을 만든다.
        String temp(s);     // RAII 기법 : 중간에 문제가 되어도 String은 객체이므로 관련 내용은 소멸이 잘 되어 문제가 안된다. 
        // s의 버포와 자산의 버퍼를 교체한다. 
        temp.swap(*this);

        return *this;
    }
};

int main()
{
    String s1 = "hello";
    String s2 = "AAA";

    s1 = s2; //  이때를 생각해 봅시다. 
}
