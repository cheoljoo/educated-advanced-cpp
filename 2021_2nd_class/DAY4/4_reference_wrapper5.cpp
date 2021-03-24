#include <thread>
#include <functional>

void foo(int a, int b) { b = 100; }

int main()
{	
	int n = 0;

	std::thread t(&foo, 10, n); 
	
	t.join();
}
