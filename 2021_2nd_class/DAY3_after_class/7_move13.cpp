// 7_move13

template<typename T, typename U> struct PAIR
{
	T first;
	U second;

	// �Ʒ� �������� ������ ? - move ���� �ȵ�
	// PAIR(const T& a, const T& b) : first(a), second(b) {}

	// move �� �����Ϸ��� - ���� ������ ���� ��ŭ�� �Լ��� �ʿ�
	//			=> "forwarding reference"�� ����ϸ� ���� ����
	PAIR(const T& a, const T& b) : first(a), second(b) {}
	PAIR(T&& a,T&& b)       : first(std::move(a)), second(std::move(b)) {}
	PAIR(const T& a, T&& b) : first(a),            second(std::move(b)) {}
	PAIR(T&& a, const T& b) : first(std::move(a)), second(b) {}
};

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "CCCC";
	PAIR<std::string, std::string> p1(s1, std::move(s2) );
}