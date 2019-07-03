/*2_smart_pointer1
- 
*/

#include <memory>
#include <iostream>
//using namespace std;

/*
- 
*/

int main()
{
	std::shared_ptr<int> sp1(new int);
	std::shared_ptr<int> sp2 = sp1;

	std::cout << sizeof(sp1) << std::endl;		// 16
		// new int로 가리키고 , 관리 객체도 가리킨다. 2배 size
	std::cout << sp1.use_count() << std::endl; 	// 2

/*
-  아래 코드는 절대 안됩니다.
- 자원을 관리하기 위한 관리 객체가 sp3, sp4 각각 생성됩니다
*/
	int* p = new int;
	std::shared_ptr<int> sp3(p);
	std::shared_ptr<int> sp4(p);
		// sp4는 sp3의 존재를 알수 없다.
		// 이렇게 쓰면 문제가 발생하게 된다. 
		// 이렇게 절대 쓰면 안됨. 
		// 그래서 shared_ptr을 만들때 자원을 할당해야지 , 할당한 자원을 shared_ptr에 넣으면 안된다. 
	std::cout << sp3.use_count() << std::endl; 	// 1
/*
-  RAII : Resource Acquitition Is Initialization - 197 page
	- 자원을 할당하는 것은 자원 관리 객체가 초기화될때 여야 한다. 
*/
	std::shared_ptr<int> sp5(new int); // ok!!


}

