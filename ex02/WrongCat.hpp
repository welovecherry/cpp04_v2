#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
/* 현재 구현에서는 WrongAnimal의 생성자가 이미 type을 초기화하므로, 
WrongCat에서 별도로 type을 설정할 필요가 없습니다*/
// protected:
//     std::string type;
public:
    WrongCat(const std::string &type);
    WrongCat(const WrongCat& src);
    WrongCat& operator=(const WrongCat& rhs);
    virtual ~WrongCat();
};

#endif