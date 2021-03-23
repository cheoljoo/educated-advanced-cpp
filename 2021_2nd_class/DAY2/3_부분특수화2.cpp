#include <iostream>
using namespace std;

template<typename T, typename U> struct Object
{
	static void foo() { cout << "T, U" << endl; }
};


int main()
{
	Object<int, double>::foo();	// T,  U
	Object<int*, double*>::foo();  // T*, U*
	Object<int*, double>::foo(); // T*, U
	Object<int, int>::foo();     // T, T 
	Object<int, char>::foo();    // int, U
	Object<int, short>::foo();   // int, short
}
