/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:04:11 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/26 19:12:24 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap player1("Ilyas");
    player1.attack("Elasefar");
    player1.takeDamage(3);
    player1.beRepaired(5);
    return 0;
}