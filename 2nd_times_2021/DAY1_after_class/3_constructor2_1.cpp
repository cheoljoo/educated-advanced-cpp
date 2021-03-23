#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "���� ũ�� " << size << "�� �ʱ�ȭ" << std::endl;
	}
	void useBuffer() { std::cout << "���� ���" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//------------------------------------------
// ���۸� ���� PipeStream ����

// �ذ�å - "Base From Member" ��� �̸��� ���� ���
// 1. Buffer ���� ���� ��� Ŭ���� ����
struct BaseBuffer
{
	Buffer buff{ 1024 };
};

// 2. ���۸� ���� ����� ���� ����, BaseBuffer�� ���� ��� �޴´�.
class PipeStream : public BaseBuffer, public Stream
{
public:
	PipeStream() : Stream(buff) {}
};

// "google" ���� "C++ IDioms" �˻��� ������..   1��° ��ũ





int main()
{
	PipeStream ps;

}





