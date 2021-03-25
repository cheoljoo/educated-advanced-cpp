// nullptr.cpp

void foo(int* p) {}
void goo(char* p) {}

// nullptr �� ����
// 1. boost ���̺귯�� ������ �Ʒ� ó�� ���� ���
// 2. C++11 ������ "nullptr" �� Ű����� �°�..
//    "false" �� Ű���� �̰� literal , Ÿ���� "bool"
//    "nullptr" Ű���� �̰� literal, Ÿ�� "nullptr_t"
struct nullptr_t
{
	// ��ȯ ������ : ��ü�� �ٸ� Ÿ������ �Ͻ��� ��ȯ �ɶ� ȣ��.
	//				 Ư¡�� ���� Ÿ���� ǥ������ �ʽ��ϴ�.
	template<typename T> 
	operator T*() const { return 0; }
};
nullptr_t xnullptr;

int main()
{
	foo(xnullptr);  // xnullptr => int* ���� �Ͻ��� ��ȯ �ʿ�
					// xnullptr.operator int*() ��� ��ȯ ������ �Լ� ȣ��
	goo(xnullptr);
}
