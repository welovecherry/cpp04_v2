#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

// void leaks(void) {
//     system("leaks ex02");
// }

int main() {
    // atexit(leaks);
    std::cout << "------ Begin of the main statement ------\n" << std::endl;
    int size = 6;
    Animal *animals[size];

    std::cout << "------ Create all animals ------" << std::endl;
    for (int i = 0; i < size / 2; i++) {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for (int i = size / 2; i < size; i++) {
        animals[i] = new Cat();
        std::cout << std::endl;
    }
    
    std::cout << "\n------ All animals make sound ------" << std::endl;
    for (int i = 0; i < size; i++) {
        animals[i]->makeSound();
    }
    std::cout << std::endl;
    
    std::cout << "------ Delete all animals ------" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];
        std::cout << std::endl;
    }

    std::cout << "------ End of the main statement ------" << std::endl;
    return (0);
}
