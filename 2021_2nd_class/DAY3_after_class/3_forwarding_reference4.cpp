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
// T&  : lvalue �� �ްڴٴ°�
// T&& : lvalue �� rvalue�� ��� �ްڴٴ°� 
template<typename T> std::remove_reference_t<T>&& xmove(T&& obj)
{
	// �Ʒ� �ڵ�� T�� ������ �Ȱ� �ִ� ��쿡�� rvalue ĳ������ �ƴҼ� �ֽ��ϴ�.
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
