// 초기화1

int main()
{
	/*
	int n1 = 0;
	int n2(0);
	int x[2] = { 1,2 };
	*/
	// uniform initialization(일관된초기화)
	// 또는 "brace-init(중괄호초기화)"
	int n1{ 0 };
	int n2{ 0 };
	int x[2] { 1,2 };

	int n1 = { 0 };
	int n2 = { 0 };
	int x[2] = { 1,2 };

	int n3{ 3.4 }; // error.  중괄호 초기화는 데이타 손실 발생시 에러.
}