/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:37:46 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/04 23:37:46 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie() 
{
    std::cout << "Zombie " << m_name << " destroyed" << std::endl;
};

void Zombie::setName(std::string name)
{
    m_name = name;
};

void Zombie::announce() 
{
    std::cout << m_name <<":"<< " BraiiiiiiinnnzzzZ..." << std::endl;
};