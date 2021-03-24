#include <vector>
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
int main()
{
//	Data d1;
	const Data d1;           // 상수 객체
	Data d2 = std::move(d1); // move 생성자 호출
					// 단, 상수객체는 move 될수 없다.
					// 복사 생성자 호출

	Data d3 = std::move(d1); // static_cast<d1의타입&&>(d1)
						     // static_cast<const Data&&>(d1)
				
}
