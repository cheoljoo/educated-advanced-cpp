#include <iostream>
#include <vector>
#include <initializer_list>
class Point
{
	int x, y;
public:
	Point(int a)        { std::cout << "1" << std::endl; }
	Point(int a, int b) { std::cout << "2" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "3 " << std::endl; }
};
int main()
{
	Point p1(1);	// 1�� ������
	Point p2(1,2);	// 2�� ������

	Point p3( { 1, 2 } ); // 3�� ������
	Point p4{ 1,2 }; // 3�� ������, ������ 2��������
	
	Point p5(1,2,3); // error. int �� 3���� �����ڴ� ����.

	Point p6{ 1,2,3 };    // 3�� ������ ȣ��
	Point p7 = { 1,2,3 }; // ���� 3�� ������ ȣ��

	// �ٽ� : ������ ���ڷ� std::initializer_list<int> �� ������ 
	//			���� Ÿ���� "���� ����"�� ���ڸ� ������ �ִ�.
	// ��..!! STL�� �Ʒ� ó�� ����ϰ� ���ְ� �;���.
	std::vector<int> v1{ 1,2,3,4,5,6,7,8,9,10 }; // ok
	std::vector<int> v2 = { 1,2,3,4,5,6,7,8,9,10 }; // ok

	// ����!! �Ʒ� 2���� �������� �ݵ�� �˾ƾ� �մϴ�.
	std::vector<int> v3( 10, 2 ); // int 2���� ������. 
								  // 10���� ��Ҹ� 2�� �ʱ�ȭ
	std::vector<int> v4{ 10, 2 }; // std::initializer_list<int> ������
								  // 2���� 10, 2�� �ʱ�ȭ
}

