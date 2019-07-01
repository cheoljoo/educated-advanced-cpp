// casting1.cpp

#include <stdio.h>
#include <iostream>

int main()
{
    int n=5;
    //double* q = &n; // warning in C , but error in c++
    
    double* q = (double *) &n; // C style casting : ok. but it is dangerous.

    *q = 3.4;


    const int c=10; // this is syntactical.
    int *p=(int*)&c;
    *p = 20;  // so it is ok 

    printf("%d\n",c);
    printf("%d\n",*p);
}
