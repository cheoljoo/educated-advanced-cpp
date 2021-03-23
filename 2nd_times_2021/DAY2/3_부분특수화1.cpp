#include <iostream>
using namespace std;

template<typename T> class Stack
{
public:
	void push(T v) { cout << "T" << endl; }
};

int main()
{
	Stack<int>   s1; s1.push(0);
	Stack<int*>  s2; s2.push(0);
	Stack<char*> s3; s3.push(0);
}
