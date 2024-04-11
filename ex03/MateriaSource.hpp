#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#define MAX_SLOT 4

class MateriaSource : public IMateriaSource {
private:
    AMateria* slots[MAX_SLOT];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& src);
    MateriaSource& operator=(const MateriaSource& rhs);
    virtual ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const &type);
};

#endif