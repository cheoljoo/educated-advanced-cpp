#include "cppmaster.h"
#include <vector>
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
int main()
{
	Data d1;

	std::vector<Data> v;

	v.push_back(d1);            // d1의 자원을 복사해가라..!! d1은 계속 사용할거이다.
	v.push_back(std::move(d1)); // d1의 자원을 가져 가라. d1은 자원이 필요 한다.

}
