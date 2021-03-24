#include <iostream>
#include <string>
#include <vector>

// C++ string
// SSO : Simple String Optimization
// 짦은 문자열(26자)은 객체가 바로 보관
// 긴   문자열은 힙에 할당해서 보관

// move 개념
int main()
{
	std::string s1 = "hello";
	//std::string s2 = s1;		   // 자원의 복사		
	std::string s3 = std::move(s1);// 자원의 이동
	
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;


	std::vector<int> v1(10, 3); 
	//std::vector<int> v2 = v1;
	std::vector<int> v2 = std::move(v1);

	std::cout << v1.size() << std::endl; 
	std::cout << v2.size() << std::endl; 
}

