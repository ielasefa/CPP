/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:37:49 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/04 23:37:49 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
  if(N <= 0)
    return NULL;
  Zombie *horde;
  horde = new Zombie[N];
  for(int i = 0; i < N; i++)
  {
    horde[i].setName(name);
  }
  return horde;
}