/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:30:00 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/10 19:20:50 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap obj1("ilyas");

    obj1.attack("ILYAS");
    obj1.takeDamage(50);
    obj1.beRepaired(40);
    obj1.highFivesGuys();
}

