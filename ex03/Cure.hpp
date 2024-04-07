#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria {
public:
    Cure();
    Cure(Cure const &src);
    Cure &operator=(Cure const &rhs);
    virtual ~Cure();

    virtual Cure* clone() const;
    virtual void use(ICharacter& target);
};


#endif