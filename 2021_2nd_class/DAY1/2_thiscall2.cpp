class Dialog
{
public:
	void Close() {}
};

void foo() {} 

int main()
{
	void(*f1)() = &foo;				
	void(*f2)() = &Dialog::Close;	
}






