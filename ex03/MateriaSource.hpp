#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* slots[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& src);
    MateriaSource& operator=(const MateriaSource& rhs);
    virtual ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const &type);
};

#endif