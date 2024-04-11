#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

// void leaks(void)
// {
// 	system("leaks ex03");
// }

int main() {
    //atexit(leaks);

    std::cout << "------ Begin of the main statement ------\n" << std::endl;
    std::cout << "------ ice & cure learn test ------" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice()); 
    std::cout << std::endl;

    src->learnMateria(new Cure());
    std::cout << std::endl;

    std::cout << "------ ice & cure equip test ------" << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << std::endl;
    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    std::cout << "------ use() test ------" << std::endl;
    ICharacter* bob = new Character("bob"); 
    me->use(0, *bob);
    std::cout << std::endl;
    me->use(1, *bob);
    std::cout << std::endl;

    std::cout << "------ unequip() test ------" << std::endl;
    me->unequip(0);
    std::cout << std::endl;
    me->unequip(1);
    std::cout << std::endl;

    std::cout << "------ delete test ------" << std::endl;
    delete bob; 
    delete me; 
    delete src;
    
    std::cout << "------ End of the main statement ------" << std::endl;
    return (0);
}
