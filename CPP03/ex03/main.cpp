/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:30:00 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/19 01:19:02 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d("Dima");

    d.attack("enemy");           // uses ScavTrap::attack via DiamondTrap
    d.takeDamage(20);
    d.beRepaired(10);
    d.guardGate();                // ScavTrap ability
    d.highFivesGuys();            // FragTrap ability
    d.whoAmI();                   // DiamondTrap-specific

    return 0;
}

