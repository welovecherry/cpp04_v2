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

    std::cout << k->getType() << " " << std::endl; // "WrongCat"을 출력하도록 예상됩니다.
    std::cout << std::endl;

    k->makeSound(); // "Wrong sound"을 출력합니다. WrongCat은 WrongAnimal의 makeSound()를 상속받습니다.
    meta2->makeSound(); // "Wrong sound"을 출력합니다.

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
