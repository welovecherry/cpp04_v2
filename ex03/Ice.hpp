#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Ice : public AMateria {
public:
    Ice();
    Ice(Ice const &src);
    Ice &operator=(Ice const &rhs);
    ~Ice();

    Ice* clone() const;
    void use(ICharacter& target);
};

#endif
