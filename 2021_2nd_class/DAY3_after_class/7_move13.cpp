// 7_move13

template<typename T, typename U> struct PAIR
{
	T first;
	U second;

	// 아래 생성자의 단점은 ? - move 지원 안됨
	// PAIR(const T& a, const T& b) : first(a), second(b) {}

	// move 를 지원하려면 - 인자 갯수의 제곱 만큼의 함수가 필요
	//			=> "forwarding reference"를 사용하면 편리해 진다
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