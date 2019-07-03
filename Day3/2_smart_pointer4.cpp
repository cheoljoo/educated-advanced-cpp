/*2_smart_pointer4
- 
*/

#include <iostream>
#include <memory>
//using namespace std;

/*
- 
*/

int main()
{
	int* rp = nullptr;

	std::weak_ptr<int> wp; 	// 참조 계수가 증가하지 않는 스마트포인터 (raw pointer대신 이것 사용) 

	{
		std::shared_ptr<int> sp1(new int);
		std::shared_ptr<int> sp2 = sp1;	// 참조 계수 증가

		// 수명에 관여가기 싫으면 진짜 포인터를 쓰면 된다. 
		// raw pointer(진짜 포인터)의 문제점 : 객체가 파되었는지 알수 없다.
		rp = sp1.get();	// 진짜 포인터 꺼내기
		wp = sp1;

		std::cout << sp1.use_count() << std::endl;	// 2
	}

	if(wp.expired()){
		std::cout << "wp : 객체가 파괴됨" << std::endl;
	}

	if(rp != nullptr)
	{
		std::cout << "객체 사용" << std::endl; 	//이 객체는 이미 파괴됨.
	}

}

/*
- make_shared를 쓰면 합쳐서 관리를 한다.
	- 그러므로 , weak pointer를 사용하면 weak pointer가 없어질때까지 객체 memory도 반환되지 않는다.
	- 단지 , 소멸자만 call된다.

- android  148 line  RefBase.cpp
*/



