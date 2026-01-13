/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:39:01 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/15 21:39:01 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) 
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intval) : value(intval << Fixed::fractionalBits)
{
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float flotval) : value((roundf(flotval * (1 << Fixed::fractionalBits))))
{
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if(this != &other)
     value = other.getRawBits();
  return *this;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
  return (float)value / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
  return (int)value / (1 << fractionalBits);
}

int Fixed::getRawBits(void) const
{
  return value;
}

void Fixed::setRawBits(int const raw)
{
  value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
    out << f.toFloat();
    return out;         
}