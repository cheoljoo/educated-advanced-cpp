// 템플릿 부분 특수화

#include <iostream>

// template 강의의 이것이 나온 부분의 link를 추가하면 좋을 것이다. (연결)
// primary template
template <typename T> class Stack
{
public:
    void push(T a){ std::cout << "T" << std::endl; }
};
// partial specialization
template <typename T> class Stack<T*>
{
public:
    void push(T* a){ std::cout << "T*" << std::endl; }
};
// specialization
template<> class Stack<char*>
{
public:
    void push(char* a){ std::cout << "char*" << std::endl; }
};

int main()
{
    Stack<int> s1; s1.push(0);
    Stack<int*> s2; s2.push(0);
    Stack<char*> s3; s3.push(0);
}

