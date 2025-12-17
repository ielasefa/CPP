/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:49:10 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/17 15:50:29 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(AMateria const &copy)
{
    *this = copy;
}

AMateria   &AMateria::operator=(AMateria const &src)
{
    if (this != &src)
        type = src.getType();
    return (*this);
}

std::string const & AMateria::getType() const
{
    return this->type;
}

AMateria::~AMateria()
{
}
void AMateria::use(ICharacter& target)
{
    (void)target;
}
