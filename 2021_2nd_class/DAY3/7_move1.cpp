#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string s1 = "hello";
	std::string s2 = s1;		
	
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;


	std::vector<int> v1(10, 3); 
	std::vector<int> v2 = v1;

	std::cout << v1.size() << std::endl; 
	std::cout << v2.size() << std::endl; 
}

