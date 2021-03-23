/*1_member_pointer6
- 
*/

#include <iostream>
//using namespace std;

/*
- 모든 함수 pointer를 담을수 있는 pointer
	- void* 에는 member pointer를 못 담았다. 
*/

/*
 *   일반함수 포인터 : IAction with execute()
 *   멤버함수 포인터 : IAction with execute()
 */

class Button
{
	void(*handler)();
public:
	void Click()
	{
		// 클릭된 사실을 외부에 알리려고 합니다. 
		handler();
	}
};

int main()
{
	Button btn;
	btn.Click();	// 사용자가 버튼을 누르면 이 함수가 호출된다고 가정

}
