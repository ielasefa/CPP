/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:41:45 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/13 23:41:45 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy Constructor Called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Copy Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}