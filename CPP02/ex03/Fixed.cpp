/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:46:04 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/12 09:46:04 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int value) : value( value << fractionalBits) {}
Fixed::Fixed(const float flotval) : value((roundf(flotval * (1 << Fixed::fractionalBits)))){}
Fixed::Fixed(const Fixed &other) : value(other.value) {}

Fixed &Fixed::operator=(const Fixed &other)
{
  if(this != &other)
    value = other.value;
  return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
  return value;
}

void Fixed::setRawBits(int const raw)
{
  value = raw;
}

float Fixed::toFloat( void ) const
{
  return (float)value / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
  return (int)value / (1 << fractionalBits);
}


std::ostream& operator<<(std::ostream &out, const Fixed fixed)
{
  out << fixed.toFloat();
  return out;
}

bool Fixed::operator>(const Fixed &other) const
{
  return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
  return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
  return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
  return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
  return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
  return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
  Fixed rslt;
  rslt.setRawBits(this->getRawBits() + other.getRawBits());
  return rslt;
}

Fixed Fixed::operator-(const Fixed &other) const
{
  Fixed rslt;
  rslt.setRawBits(this->getRawBits() - other.getRawBits());
  return rslt;
}

Fixed Fixed::operator*(const Fixed &other) const
{
  Fixed rslt;
  rslt.setRawBits((this->getRawBits() * other.getRawBits()) / (1 << fractionalBits));
  return rslt;
}

Fixed Fixed::operator/(const Fixed &other) const
{
  Fixed rslt;
  rslt.setRawBits((this->getRawBits() / other.getRawBits())* (1 << fractionalBits));
  return rslt;
}

Fixed& Fixed::operator++() //prefix ++a
{
  setRawBits(this->getRawBits() + 1);
  return *this;
}

Fixed Fixed::operator++(int) //postfix a++
{
  Fixed tmp = *this;
  setRawBits(this->getRawBits() + 1);
  return tmp;
}

Fixed& Fixed::operator--()//prefix
{
  setRawBits(this->getRawBits() - 1);
  return *this;
}

Fixed Fixed::operator--(int) //postfix
{
  Fixed tmp = *this;
  setRawBits(this->getRawBits() - 1);
  return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
  if(a < b)
    return a;
  return b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
 {
  if(a > b)
    return a;
  return b;
 }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
  if(a < b)
    return a;
  return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
  if(a > b)
    return a;
  return b;
}