
//memfun4.cpp
#include <iostream>
class Foo{
public:
  int f(char* c=0){
    std::cout<<"Foo::f()"<<std::endl;
    return 1;
  }
};
 
class Bar{
public:
  void b(int i=0){
    std::cout<<"Bar::b()"<<std::endl;
  }
};
 
class FooDerived:public Foo{
public:
  int f(char* c=0){
    std::cout<<"FooDerived::f()"<<std::endl;
    return 1;
  }
};
 
int main(int argc, char* argv[]){
  typedef  int (Foo::*FPTR) (char*);
  typedef  void (Bar::*BPTR) (int);
  typedef  int (FooDerived::*FDPTR) (char*);
 
  FPTR fptr = &Foo::f;
  BPTR bptr = &Bar::b;
  FDPTR fdptr = &FooDerived::f;
 
  //Bptr = static_cast<void (Bar::*) (int)> (fptr); //error
  fdptr = static_cast<int (Foo::*) (char*)> (fptr); //OK: contravariance
 
  Bar obj;
  ( obj.*(BPTR) fptr )(1);//call: Foo::f()
	// Although we want to call Bar::b(), but Foo::f() is called because fptr has static binding. (also see Member function call and this pointer
}
