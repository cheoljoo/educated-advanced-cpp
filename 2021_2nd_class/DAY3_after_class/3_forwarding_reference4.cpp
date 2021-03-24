#include "cppmaster.h"
using namespace std;

class Data
{
public:
	Data() = default;
	Data(const Data& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(const Data&) { LOG_FUNCTION_NAME(); return *this; }
	Data(Data&& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(Data&&) { LOG_FUNCTION_NAME(); return *this; }
};
// T&  : lvalue 만 받겠다는것
// T&& : lvalue 와 rvalue를 모두 받겠다는것 
template<typename T> std::remove_reference_t<T>&& xmove(T&& obj)
{
	// 아래 코드는 T가 참조를 안고 있는 경우에는 rvalue 캐스팅이 아닐수 있습니다.
	//return static_cast<T&&>(obj);
	return static_cast<std::remove_reference_t<T>&&>(obj);
}
Data foo()
{
	Data d;
	return d;
}

int main()
{
	Data d1;
		
	Data d2 = xmove(d1);	// T=Data&,   T&&=Data& &&  => Data&, static_cast<Data&>(d1)
	Data d3 = xmove(foo());
	Data d4 = std::move(foo());
}
