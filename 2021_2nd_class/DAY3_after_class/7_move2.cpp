#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? 
/*
// 복사에 의한 swap : 느리다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
*/
// 이동에 의한 swap : 빠르다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}
// 특정 알고리즘 작성시 std::move()를 적절히 사용하면 빨라진다.
// 1. 클래스 사용자
//    알고리즘 작성시 적절하게 std::move()를 사용해라!!

// 2. 클래스 작성자
//    내가 만든 클래스가 move 개념을 지원하려면 어떻게 해야 하는가 ?
People p1;
People p2 = std::move(p1); // People 에 move를 위한 코드가 있어야 한다. - 어렵다.




