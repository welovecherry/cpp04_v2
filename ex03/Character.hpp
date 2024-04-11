#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#define MAX_SLOT 4

class AMateria;

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[MAX_SLOT];
    int addr_idx;
    AMateria* addr_tmp[MAX_SLOT];

public:
    Character(std::string const &name);
    Character(Character const &src);
    Character &operator=(Character const &rhs);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};
#endif