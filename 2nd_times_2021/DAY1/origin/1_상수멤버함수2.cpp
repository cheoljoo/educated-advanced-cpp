class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea()  { return w * h; }
};

void foo(Rect r)
{
	int n = r.getArea(); 
}
int main()
{
	Rect r(1,2,3,4);	
	int n = r.getArea();
	foo(r);
}
