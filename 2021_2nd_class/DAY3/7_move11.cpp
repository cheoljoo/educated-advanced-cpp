#include <iostream>
#include <string>
#include <vector>
#include "cppmaster.h"

class Data
{
public:
	Data() = default;
	Data(const Data& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(const Data&) { LOG_FUNCTION_NAME(); return *this; }
	Data(Data&& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(Data&&) { LOG_FUNCTION_NAME(); return *this; }
};

class Test
{
	Data data;
public:
	void setData(Data d) { data = d; }
};

int main()
{
	Data d;

	Test test;
	test.setData(d);
}








