#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

 void leaks(void) {
     system("leaks ex00");
 }

int main(void) {
     atexit(leaks);
    std::cout << "------ Begin of the main statement ------\n" << std::endl;

    const Animal* meta = new Animal();
    std::cout << std::endl;

    const Animal* i = new Cat();
    std::cout << std::endl;

    const Animal* j = new Dog();
    std::cout << std::endl;
    
    std::cout << i->getType() << " " << std::endl; 
    std::cout << j->getType() << " " << std::endl; 
    std::cout << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n------ Testing WrongAnimal Class ------" << std::endl; 
    const WrongAnimal* meta2 = new WrongAnimal();
    std::cout << std::endl;

    const WrongAnimal* k = new WrongCat();
    std::cout << std::endl;

    std::cout << k->getType() << " " << std::endl;
    std::cout << std::endl;

    k->makeSound();
    meta2->makeSound();

    std::cout << "\n------ Deleting all objects ------" << std::endl;
    delete meta;
    std::cout << std::endl;

    delete i;
    std::cout << std::endl;
    
    delete j;
    std::cout << std::endl;
    
    delete meta2;
    std::cout << std::endl;
    
    delete k;
    std::cout << "------ End of the main statement ------" << std::endl;
    return 0;
}
