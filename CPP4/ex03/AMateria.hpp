/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:19:45 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/16 22:51:30 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>

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