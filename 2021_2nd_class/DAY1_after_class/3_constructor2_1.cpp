#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "버퍼 크기 " << size << "로 초기화" << std::endl;
	}
	void useBuffer() { std::cout << "버퍼 사용" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//------------------------------------------
// 버퍼를 가진 PipeStream 설계

// 해결책 - "Base From Member" 라는 이름을 가진 기술
// 1. Buffer 만을 가진 기반 클래스 설계
struct BaseBuffer
{
	Buffer buff{ 1024 };
};

// 2. 버퍼를 직접 멤버로 놓지 말고, BaseBuffer로 부터 상속 받는다.
class PipeStream : public BaseBuffer, public Stream
{
public:
	PipeStream() : Stream(buff) {}
};

// "google" 에서 "C++ IDioms" 검색해 보세요..   1번째 링크





int main()
{
	PipeStream ps;

}





