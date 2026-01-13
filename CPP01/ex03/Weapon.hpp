/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:28:55 by iel-asef          #+#    #+#             */
/*   Updated: 2025/10/27 16:28:55 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <ostream>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(const std::string& type);
        ~Weapon();

       std::string getType() const;
        void setType(const std::string& newType);
};

#endif