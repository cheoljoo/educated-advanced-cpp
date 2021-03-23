/* 4_coercion 43 page
- coercion
    - int가 double로 변환되면 , Point<int>도 Point<double>로 변환되어야 한다. 
*/

#include <iostream>
//using namespace std;

/*
- 
*/

class Animal {};
class Dog : public Animal {};

int main()
{
    std::shared_ptr<Dog> pDog = std::make_shared<Dog>();
    std::shared_prt<Animal> pAnimal = pDog;
}
