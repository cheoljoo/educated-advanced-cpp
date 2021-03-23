// 핵심 : 상수 멤버 함수는 선택이 아닌 필수 문법입니다.
//       상태를 변경하지 않는 모든 멤버함수(getter) 는 반드시 상수 멤버함수로 해야
//       합니다.
// github.com/codenuri/SOURCE 에 소스 바로 올리 겠습니다.
class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; }
};
//void foo(Rect r) // call by value : 복사본 생성
void foo(const Rect& r) // const Rect& : 가장 널리 사용
{
	int n = r.getArea(); // error
}
int main()
{
	Rect r(1,2,3,4);	 // 비 상수 객체
	int n = r.getArea(); // ok..
	foo(r);
}
