// �ʱ�ȭ1

int main()
{
	/*
	int n1 = 0;
	int n2(0);
	int x[2] = { 1,2 };
	*/
	// uniform initialization(�ϰ����ʱ�ȭ)
	// �Ǵ� "brace-init(�߰�ȣ�ʱ�ȭ)"
	int n1{ 0 };
	int n2{ 0 };
	int x[2] { 1,2 };

	int n1 = { 0 };
	int n2 = { 0 };
	int x[2] = { 1,2 };

	int n3{ 3.4 }; // error.  �߰�ȣ �ʱ�ȭ�� ����Ÿ �ս� �߻��� ����.
}