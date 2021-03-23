class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	// 모든 getter 함수는 반드시 const member function이 되어야 한다. 
	int getArea() const  { return w * h; }
};

// void foo(Rect r) // call by valule
void foo(const Rect& r)  // const Rect& : 가장 널리 이용 
{
	int n = r.getArea();    // error : const 이므로 에러 
}
int main()
{
	Rect r(1,2,3,4);	        // 비 상수 객체
	int n = r.getArea();        // ok
	foo(r);
}
