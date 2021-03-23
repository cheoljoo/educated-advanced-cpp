void f1(int&  r) {}
void f2(int&& r) {}
template<typename T> void f3(T& a)
{
}
template<typename T> void f4(T&& a)
{
}
