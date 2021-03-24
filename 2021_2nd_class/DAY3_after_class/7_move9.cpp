#include <vector>
#include "cppmaster.h"
using namespace std;

class Data
{
public:
	Data() = default;
	Data(const Data& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(const Data&) { LOG_FUNCTION_NAME(); return *this; }
	
	// move 계열 함수를 만들때는
	// 1. 되도록 예외가 발생하지 않게 만들고
	// 2. 예외가 없음을 컴파일러에게 알려주는것이 좋습니다
	// 함수() noexcept : 함수가 예외가 없음을 컴파일러에게 알리는 표기법 
	Data(Data&& d) noexcept          { LOG_FUNCTION_NAME(); }
	Data& operator=(Data&&) noexcept { LOG_FUNCTION_NAME(); return *this; }
};

int main()
{
	Data d1;
	Data d2 = d1;// 무조건 복사 생성자 사용
	Data d3 = std::move(d1); // 무조건 move 생성자 사용
	Data d4 = std::move_if_noexcept(d2); // move 생성자에 예외가 없을때만 move 사용
										// 예외가능성이 있으면 복사생성자 사용
/*
	if (std::is_nothrow_move_constructible_v<decltype(d2)>)
		return std::move(d2);
	else
		return d2;
*/

			


	std::vector<Data> v(5);

	cout << "-----" << endl;

	v.resize(10); // 이 순간의 원리를 생각해 봅시다.
	
	cout << "-----" << endl;
}







 