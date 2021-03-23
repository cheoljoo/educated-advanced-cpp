// cafe.naver.com/cppmaster 에서 

// 2일차 사전소스 받으시면 됩니다.

// VS 사용하시는 분은 "Windows SDK 버전" 설정해 주세요



class Test
{
public:
	enum { value = 1 };
	typedef int DWORD;
};
int p = 0;

template<typename T> typename T::DWORD foo(T a)
{
	// 아래 2줄에서 * 의 의미를 생각해 보세요(1. 곱하기, 2. 포인터 변수 선언)
	// "클래스이름::이름" : (1) 값
	//						(2) 타입
	//Test::value * p; // 곱하기의 의미
	//Test::DWORD * p; // 포인터 변수 선언

	// "T::이름"           : 이름을 값으로 해석
	// typename "T::이름"  : 이름을 타입으로 해석해 달라는 것

	// 핵심 : 템플릿 의존적으로 타입을 꺼낼때는
	//			typename을 적어야 한다.

	T::value * p; // ok.
	//T::DWORD * p; // error.  VC의 일부 버전 에서는 에러가 발생안함.
	typename T::DWORD * p;

	return 0;
}

int main()
{
	Test t;
	foo(t);
}
