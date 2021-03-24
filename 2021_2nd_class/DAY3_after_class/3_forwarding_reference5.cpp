#include <vector>

int main()
{
	int n = 10;

	auto& a1 = n;   // ok
//	auto& a2 = 10;  // error

	// auto �� ���ø��� ���� ��Ģ
	// T&& 
	auto&& a3 = n; // int& a3 = n
	auto&& a4 = 10;// int&& a4 = 10
	// �ٽ� : auto&& �� rvalue reference �� �ƴ϶� forwarding reference �Դϴ�.

	std::vector<int>  v1(10, 3);
	std::vector<bool> v2(10, false);
	
	auto& r1 = v1[0]; // ok.    v1[0] �� �ӽð�ü �ƴ�.
	auto& r2 = v2[0]; // error. v2[0] �� �ӽð�ü ��ȯ.
}




