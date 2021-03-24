
// 방법 1. call by value - 복사본의 overhead 가 있다.
// void foo(int n) {}

// 2. call by const reference
//    lvalue 와 rvalue를 받을수 있지만, const가 추가된다.
//    move()도 사용할수 없고, 값을 수정할수도 없다.
//void foo(const int& n) {}

// 3. const 도 없고, 복사본도 없이 받으려면 2개를 만들며 된다.
// void foo(int&  a) {}
// void foo(int&& a) {}

// 4. forwarding reference를 사용하면 3번의 함수를 자동으로 2개 만들어 준다
//    T&& 의 의도는 (int&) 와 (int&&) 의 함수를 자동으로 만들겠다는것...
//    move 등을 사용하기위해 꼭 필요
template<typename T> void foo(T&& arg) {}

// (const int&) 와 (const int&&)를 만들어야 하는 이유는 거의 없다.


int main()
{
	int n = 10;

	// lvalue 와 rvalue를 모두 받을수 있는 foo 함수를 만들고 싶다
	foo(n);
	foo(10);
}
