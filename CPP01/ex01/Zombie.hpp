/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:37:51 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/04 23:37:51 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string m_name;
    public:
        Zombie();                  
        ~Zombie();             
        void announce();
        void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif