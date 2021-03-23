// 6_enable_if5 - git �� 4_trivial3.cpp �����ؿ�����.. �ּ� ���켼��
#include <iostream>

struct Point
{
	int x, y;
	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

//	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

// github.com/aosp-mirror   �ȵ���̵� �ҽ�

// platform_system_core  �������丮 �˻�

// libutils/include/utils/typehelpers.h ���Ͽ��� copy_type �Լ� ã�Ƽ� ��� ������

template<typename T>
std::enable_if_t< std::is_trivially_copyable_v<T>>
copy(T* dst, T* src, std::size_t sz)
{
	std::cout << "���۸� ��°�� ����" << std::endl;
	memcpy(dst, src, sizeof(T)*sz);
}

template<typename T>
std::enable_if_t< !std::is_trivially_copyable_v<T>>
copy(T* dst, T* src, std::size_t sz)
{
	std::cout << "��Ҹ� �Ѱ��� ���� �����ڷ� ����" << std::endl;
	while (sz--)
	{
		new(dst) T(*src); // ���� ������ ȣ�� ��� - "placement new ����"
		++dst, ++src;
	}
}


int main()
{
	Point pt1[5] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	Point pt2[5];

	copy(pt2, pt1, 5);

}