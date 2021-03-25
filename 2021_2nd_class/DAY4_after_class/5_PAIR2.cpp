// 5_PAIR2
#include <iostream>
#include <type_traits>
#include <string>

template<typename T, typename U> struct PAIR
{
	T first;
	U second;

	// C++98 ���� ����ϴ� ��Ÿ��
	//PAIR(const T& a, const U& b) : first(a), second(b) {}
	//PAIR(T&& a, U&& b)       : first(std::move(a)), second(std::move(b)) {}
	//PAIR(const T& a, U&& b)  : first(a),            second(std::move(b)) {}
	// PAIR(T&& a, Uconst U& b) : first(std::move(a)), second(b) {}

	// C++11 ���� ���Ǵ� �������� ����� ������
	template<typename A, typename B> 
	PAIR(A&& a, B&& b) :  first( std::forward<A>(a) ), second( std::forward<B>(b) )
	{
		// ������ �´� ���� ?
//		first = a;				// ������ "����"
//		first = std::move(a);	// ������ "rvalue" ĳ���� �̹Ƿ�, "�׻� move"
//		first = std::forward(a);// ������ ���ڸ� ��� ���´��Ŀ� ���� �ٸ� ĳ����	
								// ����
	}
};

int main()
{
	std::string s1 = "AA";
	std::string s2 = "BBBB";

	PAIR<std::string, std::string> p1(s1, s2);
	PAIR<std::string, std::string> p2(s1, std::move(s2));
}

