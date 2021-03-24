#include "cppmaster.h"

// lvalue, rvalue 의 개념은 "객체가 아니라 표현식"의 개념
// expression : 하나의 값으로 계산되는 코드집합

int main()
{
	int n = 10;
	
	LOG_VALUE_CATEGORY(n);		// cppmaster.h 헤더
	LOG_VALUE_CATEGORY(n+5);
	LOG_VALUE_CATEGORY(++n);
	LOG_VALUE_CATEGORY(n++);
	LOG_VALUE_CATEGORY(3.4);

	n = 10;		// 'n' 이라는 코드(표현식은) lvalue
//	n + 5 = 10; // error. 'n+5' 이라는 표현식은 rvalue
//	n + 2 * 5 = 30; // error. 'n+2*5' 표현식은 rvalue
//	++n = 10;	 // ?

	int k = 3;
	int s = ++k * ++k;  // s는 얼마일까요 ?

}




