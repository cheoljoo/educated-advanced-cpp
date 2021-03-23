#include <iostream>
#include "cppmaster.h"

class Data
{
public:
	Data() = default;
	Data(const Data& d)			{ LOG_FUNCTION_NAME(); }
	Data& operator=(const Data&) { LOG_FUNCTION_NAME(); return *this; }
	Data(Data&& d)			{ LOG_FUNCTION_NAME(); }
	Data& operator=(Data&&) { LOG_FUNCTION_NAME(); return *this; }
};
class Object
{
	Data data;
public:		  
	Object() {}
};
int main()
{
	Object o1;
	Object o2 = o1;
	o2 = o1;

	Object o3 = std::move(o1);
	o3 = std::move(o2);
}
