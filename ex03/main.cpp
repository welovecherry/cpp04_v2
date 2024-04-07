#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>
// #include <unistd.h>


// void leaks(void)
// {
// 	system("leaks a.out");
// }

int main() {
    // atexit(leaks);
    std::cout << "------ Begin of the main statement ------\n" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice()); 
    std::cout << std::endl;
    src->learnMateria(new Cure());
    std::cout << std::endl;

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << std::endl;
    
    tmp = src->createMateria("cure"); //  Returns 0 if the type is unknown.
    me->equip(tmp);
    std::cout << std::endl;

    ICharacter* bob = new Character("bob"); 
    me->use(0, *bob);
    std::cout << std::endl;
    me->use(1, *bob);
    std::cout << std::endl;

    delete bob; 
    delete me; 
    delete src;

    std::cout << "------ End of the main statement ------" << std::endl;
    return (0);
}
