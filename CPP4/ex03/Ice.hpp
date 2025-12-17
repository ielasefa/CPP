/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:35:58 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/18 00:00:00 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &other);
        Ice & operator=(const Ice &other);
        virtual ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
