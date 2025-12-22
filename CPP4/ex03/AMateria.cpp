#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(AMateria const &copy) { *this = copy; }

AMateria & AMateria::operator=(AMateria const &src)
{
    if (this != &src) type = src.getType();
    return *this;
}

std::string const & AMateria::getType() const { return this->type; }

AMateria::~AMateria() {}

void AMateria::use(ICharacter& target) { (void)target; }
