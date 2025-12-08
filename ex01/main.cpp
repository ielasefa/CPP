/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:30:00 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/27 00:26:11 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap obj("Scavy");

    obj.attack("Enemy");
    obj.takeDamage(20);
    obj.beRepaired(10);
    obj.guardGate();

    return 0;
}

