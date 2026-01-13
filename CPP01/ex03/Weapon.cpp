/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:28:53 by iel-asef          #+#    #+#             */
/*   Updated: 2025/10/27 16:28:53 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) 
{}

Weapon::~Weapon(){}

std::string Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string& newType)
{
    type = newType;
}