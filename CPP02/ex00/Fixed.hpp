/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:45:40 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/12 09:45:40 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
    private:
        int value;
        static const int fractionalBits = 8;
    public:
        Fixed(); // Default constructor
        Fixed(const Fixed &zother); // Copy constructor
        Fixed &operator=(const Fixed &other); // Assignment operator
        ~Fixed(); // Destructor
        
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif