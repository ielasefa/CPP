/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:36:53 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/04 23:36:53 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zombie("ILYAS");
    zombie.announce();

    Zombie* heapZombie = newZombie("Aziz");
    heapZombie->announce();
    
    randomChump("Elasefar");
    
    delete heapZombie;
    return 0;
}