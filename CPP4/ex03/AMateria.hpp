/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:19:45 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/22 23:37:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP_4242
#define AMATERIA_HPP_4242

#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string type;
        
    public:
        AMateria(std::string const & type);
        AMateria(AMateria const &copy);
        AMateria & operator=(AMateria const &src);
        virtual ~AMateria();

        std::string const & getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
