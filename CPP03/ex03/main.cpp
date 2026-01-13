/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:30:00 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/10 19:16:27 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d("Dima");

    d.attack("enemy");        
    d.takeDamage(20);
    d.beRepaired(10);
    d.guardGate();                
    d.highFivesGuys();            
    d.whoAmI();                  

    return 0;
}
