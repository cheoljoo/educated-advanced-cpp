#include <iostream>
#include <vector>


template<typename T>
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

template<typename T>
class RefCount
{
	mutable int refCount = 0; // mutable ��� ����Ÿ
						      // ��� ��� �Լ��ȿ����� ���� �����Ҽ� �ְ� �ش޶�.
public:
	// ��������� ����/���� �ϴ� �Լ��� ��� ��� �Լ��� �Ǿ�� �մϴ�.
	// �����ü�� ��������� �Ҽ� �־�� �մϴ�.
	void AddRef()  const { ++refCount; }

	// ��� ��� �Լ��ȿ����� this�� "const Ÿ��* this" �Դϴ�.
	void Release() const  // Release( const RefCount* this )
	{
		//x = 10; // this->x = 10;  ���⼭ this Ÿ���� const RefCount �� error. 

		if (--refCount == 0)
			// delete static_cast<T*>(this); // ?? ������ ����
			// static_cast<Truck*>(const RefCount* this ) ���
			// delete static_cast<T*>( const_cast<RefCount*>(this) ); // �̷��� �ϰų�!
			delete static_cast<const T*>(this); // �̷��Ե� ����
	}

protected:
	~RefCount() { std::cout << "~RefCount" << std::endl; }
};



class Truck : public RefCount< Truck >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	const Truck* p = new Truck;

	p->AddRef(); // �Ǿ� �ұ�� ? �ȵǾ� �ұ� ?
	p->Release();
}







