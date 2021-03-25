#include <iostream>
#include <functional> 

// �Լ� ��� �Լ���ü�� ���ڷ� ������
// F f : ���纻 ������ �������
// F& f: rvalue(�ӽð�ü)�� ������ ����.
// const F& f :  f.operator()(1, 2) ȣ�⿡�� ()�����ڰ� �ݵ�� ����Լ��̾�� �Ѵ�.
//				()�����ڰ� ������ �Լ��� �ƴϸ� ����

template<typename F, typename ... Ts>
decltype(auto) chronometry(F&& f, Ts&& ... args)
{
	return std::invoke(f, std::forward<Ts>(args)...);
}

// Callable Object : ()�� ����ؼ� ȣ�� ������ ��� �͵�
//					�Լ�, ()�����ڸ� �������� Ŭ����, �Լ� ������, ����Լ� ������,����ǥ����
//							(�Լ���ü)
struct Add
{
	// ���� : ��� ����Ÿ Ȱ�밡��
	int count = 0;

	int operator()(int a, int b) //const
	{
		++count;			// �Լ� ȣ�� Ƚ�� �ľ�. �Ϲ��Լ��� �ɱ�� ?
		return a + b;
	}
};

int main()
{
	Add add;
	int n = add(1, 2); // add.operator()(1, 2)�� ����
}



