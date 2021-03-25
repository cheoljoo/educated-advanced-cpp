#include <iostream>
// C++11�� ����Ʈ�����͸� ����Ϸ��� �ʿ��� ���
#include <memory>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// �ٽ� 1. 
	std::shared_ptr<int> p1(new int);  
	std::shared_ptr<int> p2 = new int; 

	// �ٽ� 2. ����Ʈ �������� ũ��
	std::cout << sizeof(p3)   << std::endl; // ?
	std::cout << sizeof(int*) << std::endl; // ?

	// �ٽ� 3. -> �� . ������
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

}



