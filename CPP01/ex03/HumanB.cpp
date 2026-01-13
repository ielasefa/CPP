/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:28:43 by iel-asef          #+#    #+#             */
/*   Updated: 2025/10/27 16:28:43 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon &wpn)
{
  weapon = &wpn;
}

void HumanB::attack()
{
  std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
