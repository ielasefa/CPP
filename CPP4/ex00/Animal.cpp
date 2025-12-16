/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:22:52 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/24 17:54:31 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::setType(const std::string &tp)
{
    type = tp;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}