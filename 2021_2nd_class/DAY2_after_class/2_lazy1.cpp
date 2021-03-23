// 아래 코드는 왜 에러일까요 ?
// int 타입 변수를 * 하고 있다.
/*
class A
{
	int data;
public:
	void foo() { *data = 10; } 
};
int main()
{
	A a;
}
*/
// 왜 아래 코드는 에러가 없을까요 ?
template<typename T> class A
{
	T data;
public:
	void foo() { *data = 10; }
};
int main()
{
	A<int> a;
	a.foo();   // 이 코드가 있어야 에러 발생
}

// 핵심 : 클래스 템플릿의 멤버 함수중 "사용된것"만 인스턴스화("템플릿" => "C++코드")
//		됩니다.







