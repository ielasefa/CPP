/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:32:32 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/18 00:00:00 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &other);
        Cure & operator=(const Cure &other);
        virtual ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
