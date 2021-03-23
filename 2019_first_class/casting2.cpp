// casting2.cpp
// c++ style casting 1. static_cast
// 1. 연관성이 있는 타입끼리의 캐스팅
// 2. 표준 타입을 값으로 캐스팅
// 3. void* 를 다른 타입으로 캐스팅
#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	double d = 3.4;
	int n = static_cast<int>(d); // double => int  : ok

	//int *p1 = static_cast<int*>(&d);	// double *=>int* : error
	int *p2 = static_cast<int*>(malloc(100));  // void* => int* : ok 
	const int c=10;
	int *p3 = static_cast<int*>(&c);	// const int* => int* : error
}
