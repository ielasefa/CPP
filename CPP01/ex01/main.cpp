/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:37:44 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/04 23:37:44 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{   
    int n = 5;
    Zombie *horde = zombieHorde(n,"Zed");
    if(!horde)
        return(1);
    for(int i = 0; i < n; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
}
