#include <vector>
#include "cppmaster.h"
using namespace std;

//void f1() noexcept       {} // 예외가 없다.
//void f1() noexcept(true) {} // 예외가 없다.
//void f1() noexcept(false) {} // 예외가 있을수 있다.

// 2:00 시에 시작 합니다.
class Data
{
	std::string name;
public:
	Data() = default;
	Data(const Data& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(const Data&) { LOG_FUNCTION_NAME(); return *this; }


	// 아래 move 생성자는 예외가 없을까 ?

	Data(Data&& d) noexcept(  std::is_nothrow_move_constructible_v<std::string> )
		: name(std::move(d.name))  { }


	Data& operator=(Data&&) noexcept {  return *this; }
};








int main()
{
	Data d1;
	Data d2 = d1;// 무조건 복사 생성자 사용
	Data d3 = std::move(d1); // 무조건 move 생성자 사용
	Data d4 = std::move_if_noexcept(d2);

	std::vector<Data> v(5);

	cout << "-----" << endl;

	v.resize(10); 

	cout << "-----" << endl;


	std::pair<std::string, std::string> p1; // 디폴트 생성자
}







