#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

/*Dog와 Cat 클래스는 각각 Animal 클래스로부터 상속받아 makeSound() 함수를 오버라이딩(재정의)합니다. 
따라서, 각각의 객체는 자신에게 해당하는 소리를 출력합니다.*/

int main(void) {
    std::cout << "------ Begin of the main statement ------\n" << std::endl;

    const Animal* meta = new Animal();
    std::cout << std::endl;

    const Animal* i = new Cat();
    std::cout << std::endl;

    const Animal* j = new Dog();
    std::cout << std::endl;
    
    std::cout << i->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl; 
    std::cout << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n------ Testing WrongAnimal Class ------" << std::endl; 
    WrongAnimal *wrongAnimal = new WrongAnimal();
    std::cout << wrongAnimal->getType() << " " << std::endl;

    std::cout << "\n------ Testing WrongCat Class ------" << std::endl;
    WrongCat *wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;


    std::cout << "\n------ Deleting all objects ------" << std::endl;
    delete meta;
    std::cout << std::endl;

    delete i;
    std::cout << std::endl;
    
    delete j;
    std::cout << std::endl;
    
    delete wrongAnimal;
    std::cout << std::endl;
    
    delete wrongCat;
    std::cout << "------ End of the main statement ------" << std::endl;
    return 0;
}

//int main(void) {
//    std::cout << "------ Begin of the main statement ------\n" << std::endl;

//    std::cout << "------ Testing Animal Class ------" << std::endl;
//    Animal *genericAnimal = new Animal("General Animal");
//    std::cout << "Animal type: " << genericAnimal->getType() << std::endl;
//    genericAnimal->makeSound();

//    std::cout << "\n------ Testing Cat Class ------" << std::endl;
//    Cat *cat = new Cat();
//    std::cout << "Cat type: " << cat->getType() << std::endl;
//    cat->makeSound();

//    std::cout << "\n------ Testing Dog Class ------" << std::endl;
//    Dog *dog = new Dog();
//    std::cout << "Dog type: " << dog->getType() << std::endl;
//    dog->makeSound();

//    std::cout << "\n---------------------------------------" << std::endl;
//    std::cout << "\n------ Testing WrongAnimal Class ------" << std::endl;
//    WrongAnimal *genericWrongAnimal = new WrongAnimal("Generic WrongAnimal");
//    std::cout << "WrongAnimal Type: " << genericWrongAnimal->getType() << std::endl;
//    genericWrongAnimal->makeSound();

//    std::cout << "\n------ Testing WrongCat Class ------" << std::endl;
//    WrongCat *wrongCat = new WrongCat("WrongCat");
//    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
//    wrongCat->makeSound();

//    std::cout << "\n------ Deleting all objects ------" << std::endl;
//    delete genericAnimal;
//    std::cout << std::endl;
    
//    delete cat;
//    std::cout << std::endl;
    
//    delete dog;
//    std::cout << std::endl;
    
//    std::cout << "------ End of the main statement ------" << std::endl;
//    return (0);
//}