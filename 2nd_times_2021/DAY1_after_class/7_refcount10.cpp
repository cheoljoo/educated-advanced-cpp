#include <iostream>
#include <vector>


template<typename T>
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

// 클래스 템플릿 설계시 타입 인자 T를 사용하지 않은 멤버 함수는
// 템플릿이 아닌 기반 클래스를 설계해서 상속받게 하자.
// "thin template" 또는 "template hoisting" 이라는 이름을 가진 기술
class RefCountBase
{
protected:
	mutable int refCount = 0;
public:
	void AddRef()  const { ++refCount; }

protected:
	~RefCountBase() { std::cout << "~RefCountBase" << std::endl; }
};
// github.com/webkit
// webkit/source/wtf/wtf/RefCounted.h   이 소스 열어 보세요
//
// std::default_delete<T> : 표준에 있는 메모리 해제 함수 객체
//							내부적으로 delete로 삭제.
template<typename T, typename Del = std::default_delete<T> >
class RefCount : public RefCountBase
{
public:
	void Release() const
	{
		if (--refCount == 0)
		{
		//	delete static_cast<const T*>(this);

			Del d; // 삭제용 함수객체
			//d( static_cast<const T*>(this) );	 // 이제는 이렇게 안되고		
			d(static_cast<T*>(const_cast<RefCount*>(this)));	 // 이렇게 해야 합니다.
		}
	}
};

class Truck : public RefCount< Truck  >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
//	AutoPtr<Truck> p = new Truck;
	AutoPtr<Truck> p = static_cast<Truck*>( malloc(sizeof(Truck))) ;

}
// 멀티 스레드 안정성을 위해서도 "상수 멤버 함수", "상수 객체"가 좋다.
// 최적화도 도움이 된다.
// 변경되지 않으므로 "객체의 공유" 기술에도 사용

//const char* p1 = "hello";
//const char* p2 = "hello";
//printf("%p, %p\n", p1, p2); // 동일 주소..

// 모든 변수를 값을 변경할수 없게 하자!!!!! ===> "Haskell 언어와 같은 함수형언어"


// 질문
AutoPtr<int> p = new int;// 될까요 ???
// 우리가 만든 AutoPtr은 반드시 RefCount 에서 파생 되어야 합니다.
// 즉, 참조계수를 가지는 사용자 정의 타입만 가능

std::shared_ptr<int> p = new int; // ok.. 그런데 결국 참조계수가 필요 합니다.
								// 별도의 참조계수 메모리 할당.

// cafe.naver.com/cppmaster 에 오늘 소스 올리겠습니다.





