#include <thread>
#include <functional>

void foo(int a, int& b)
{
	b = 100; 
}
int main()
{	
	int n = 0;

//	std::thread t(&foo, 10, n); // 컴파일 에러
	std::thread t(&foo, 10, std::ref(n)); // ok . n을 참조로 보내달라는 의미
	
	t.join();

	// 핵심
	int n = 0;
	chronometry(foo, 1, n); // foo가 실행중 n은 절대 파괴되지 않습니다
							// 완벽한 전달이 안전!!!

	std::thread t(foo, 1, n); // foo가 스레드로 실행중 n은 파괴될수 있다. 에러
	std::thread t(foo, 1, std::ref(n)); // 위험 하지만.. 조심할테니 참조로 보내달라
}






