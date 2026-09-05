/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:41:56 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/16 18:58:20 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &src);
        ~ScalarConverter();

        static void convert(const std::string &input);
            
};

#endif 
