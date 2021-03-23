#include <iostream>
#include <thread>
#include <atomic>
//int obj = 0;

std::atomic<int> obj = 0; // C++11 부터 지원하는 "원자연산" 타입

int main()
{
	++obj; // 멀티 스레드에 안전할까요 ?  ok..

	obj.fetch_add(1); // 위 한줄과 동일
					// 1. OS가 가진 mutex 등으로 동기화 할것이다.
					// 2. OS가 아닌 CPU가 가진 명령어로 동기화 할것이다.=> ok..
					//  => lock free

	std::cout << obj.is_lock_free() << std::endl;// obj 타입이 lock free가 가능한가 ?


	int n = obj;
}
