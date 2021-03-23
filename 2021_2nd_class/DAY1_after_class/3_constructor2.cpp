#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size]) 
	{
		std::cout << "버퍼 크기 " << size  << "로 초기화" << std::endl;
	}
	void useBuffer() { std::cout << "버퍼 사용" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer();	}
};
//------------------------------------------
// 버퍼를 가진 PipeStream 설계
/*
class PipeStream : public Stream
{
	Buffer buff{ 1024 };  // C++11 부터 가능한 초기화
public:
	PipeStream() : Stream(buff) {}
};
*/

// 컴파일러가 위 코드를 아래 처럼 변경합니다.
class PipeStream : public Stream
{
	Buffer buff;
public:
//	PipeStream() : Stream(buff), buff{ 1024 } {} // 컴파일러가 이렇게 변경
	PipeStream() : buff(1024), Stream(buff) {} // 이렇게 코딩해도.. 실제 호출은 
												// 기반 클래스 생성자 먼저 호출
	// 결론 : 멤버 데이타는 기반 클래스 생성자에 보낼때 주의 하세요
	//		  초기화되지 않은 데이타를 전달하고 있는 것 입니다.
};



int main()
{
	PipeStream ps;

//	Buffer buff(1024);	// 1. 버퍼를 만들어서 
//	Stream stream(buff);// 2. Stream 에 전달..
}





