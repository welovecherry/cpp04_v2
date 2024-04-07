#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
// #include "Brain.hpp"

#include <iostream>

// TODO: leak check!!
/*  멤버 변수의 생성자는 클래스 생성자 내에서 명시적으로 호출되지 않는 한, 
클래스의 생성자가 호출되기 전에 자동으로 호출됩니다.
Dog 클래스에는 Brain 타입의 멤버 변수 brain이 있습니다. 
이 멤버 변수는 Dog 객체가 생성되기 전에 초기화되어야 합니다. 
멤버 변수의 초기화는 해당 클래스의 생성자가 호출되기 전에 자동으로 이루어지므로, 
Brain 클래스의 생성자가 호출됩니다.
*/
// int main() {
//     std::cout << "------ Begin of the main statement ------\n" << std::endl;
//     int size = 6;
//     Animal *animals[size];

//     std::cout << "------ Create all animals ------" << std::endl;
//     for (int i = 0; i < size / 2; i++) {
//         animals[i] = new Dog();
//         std::cout << "Dog " << i + 1 << " created.\n" << std::endl;
//     }
//     for (int i = size / 2; i < size; i++) {
//         animals[i] = new Cat();
//         std::cout << "Cat " << i - (size / 2) + 1 << " created.\n" << std::endl;
//     }
    
//     std::cout << "\n------ All animals make sound ------" << std::endl;
//     for (int i = 0; i < size; i++) {
//         animals[i]->makeSound();
//     }
//     std::cout << std::endl;
    
//     std::cout << "------ Delete all animals ------" << std::endl;
//     for (int i = 0; i < size; i++) {
//         delete animals[i];
//         std::cout << "Animal " << i + 1 << " deleted." << std::endl;
//         std::cout << std::endl;
//     }

//     std::cout << "------ End of the main statement ------" << std::endl;
//     return (0);
// }

/* *1* 가상 함수**는 부모 클래스에서 선언되어, 자식 클래스에서 필요에 따라 다르게 구현할 수 있는 함수입니다.

- *2* 추상 클래스**는 최소 하나 이상의 순수 가상 함수를 포함하는 클래스로, 
이 클래스 자체로는 객체를 만들 수 없습니다. 
대신 이 클래스를 상속받는 자식 클래스에서 순수 가상 함수를 구현해야만, 그 자식 클래스의 객체를 생성할 수 있습니다.*/
