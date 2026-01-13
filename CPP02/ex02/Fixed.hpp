/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:46:10 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/12 09:46:10 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:

  int value;
  static const int fractionalBits = 8;

public:

  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &other);
  Fixed& operator=(const Fixed &other);

  bool operator>(const Fixed &other) const; // overload comparison operators
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  Fixed operator+(const Fixed &other) const; // overload arithmitic operators
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  Fixed& operator++(); 
  Fixed operator++(int); 
  Fixed& operator--(); 
  Fixed operator--(int); 

  static Fixed& min(Fixed& a, Fixed& b); 
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const; 
  int toInt(void) const; 
};

std::ostream& operator<<(std::ostream &out, const Fixed fixed);
#endif