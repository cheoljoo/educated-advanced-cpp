// 핵심 1. 일반 함수 포인터에 멤버함수의 주소를 담을 수 없다.
// 핵심 2. 일반 함수 포인터에 static 멤버함수의 주소를 담을 수 있다.
//      3. 멤버 함수 포인터를 만들고 사용하는 방법 - main 함수 참고
#include <functional> // std::invoke() 
class Dialog
{
public:
	void Close(int) {}
	static void Close2(int) {}
};
void foo(int) {}

int main()
{
	void(*f1)(int) = &foo;  // ok
//	void(*f2)(int) = &Dialog::Close; // error. 멤버 함수는 호출시
									// this가 전달되는 함수.
//	void(*f2)(int) = &Dialog::Close2; // ok. 

	// 멤버 함수 포인터 만들기
	// 객체를 생성하지 않으면 "멤버 데이타"는 메모리에 없지만
	// "멤버 함수"는 코드 메모리에 있습니다. 주소를 얻을수 있습니다
	void( Dialog::*f2 )(int) = &Dialog::Close;

//	f2(10); // error. 멤버 함수는 호출시 객체주소가 같이 전달되어야 한다.
			// 그런데, 이 표기법은 객체가 없다.

	Dialog dlg;
//	dlg.f2(10); // error. f2라는 이름의 멤버는 없다.!

//	dlg.*f2(10); // .* : pointer to member 라는 이름의 C++ 전용 연산자
	             // 연산자 우선 순위 문제로 에러

	(dlg.*f2)(10); // ok.. 이 코드가 멤버 함수 포인터로 함수 호출하기

	// 문제점 : 함수 포인터 사용법이 다르다.
	f1(10);        // 일반 함수 포인터는 그냥 ()로 호출
	(dlg.*f2)(10); // 멤버 함수 포인터..
//	f2(&dlg, 10); // uniform call syntax 라는 이름을 가졌던 문법
				  // C++ 창시자의 C++17 만들때 제안인데 - 채택 안됨..

	// 대신 C++17의 선택  -std::invoke()
	std::invoke(f1, 10);       // f1(10) 의 의미!!
	std::invoke(f2, &dlg, 10); // (dlg.*f2)(10)
}
// g++ 10.x, vc++ 2017 이상  은 모두 c++14가 디폴트 입니다.
// g++ 소스이름.cpp -std=c++17     -std=c++20
// cl  소스이름.cpp  /std:c++latest
// 프로젝트메뉴-> 속성메뉴 -> C/C++ -> 명령줄의 아래 부분에 "/std:c++latest"추가






