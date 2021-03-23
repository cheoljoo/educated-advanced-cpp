// casting1.cpp

int main
{
    int n=5;
    //double* p = &n; // warning in C , but error in c++
    
    double* p = (double *) &n; // C style casting : ok. but it is dangerous.

    *p = 3.4;
}
