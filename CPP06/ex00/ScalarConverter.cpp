/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:43:39 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/16 17:40:13 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <climits>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

std::string CheckInput(const std::string &input)
{
    if (input.length() == 1)
    {
        if (isprint(input[0]) && !isdigit(input[0]))
            return "char";
    }

    if (input == "nanf" || input == "+inff" || input == "-inff")
        return "float";

    if (input == "nan" || input == "+inf" || input == "-inf")
        return "double";

    int i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;

    if (i == (int)input.length())
        return "unknown";

    bool allDigits = true;
    for (int j = i; j < (int)input.length(); j++)
    {
        if (!isdigit(input[j]))
        {
            allDigits = false;
            break;
        }
    }

    if (allDigits)
        return "int";

    i = 0;
    int dotCount = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;

    while (i < (int)input.length() - 1)
    {
        if (!isdigit(input[i]) && input[i] != '.')
            return "unknown";

        if (input[i] == '.')
            dotCount++;
        i++;
    }
    if (input[input.length() -1] == 'f' && dotCount == 1)
        return "float";

    i = 0;
    dotCount = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;

    while (i < (int)input.length())
    {
        if (isdigit(input[i]))
            ;
        else if (input[i] == '.')
            dotCount++;
        else
            return "unknown";
        i++;
    }

    if (dotCount == 1)
        return "double";

    return "unknown";
}


void ScalarConverter::convert(const std::string &input)
{
    std::string type = CheckInput(input);
    double base = 0;

    if (type == "char")
    {
        char c = input[0];
        base = static_cast<double>(c);
    }
    else if (type == "int")
    {
        long n = std::strtol(input.c_str(), NULL, 10);
        base = static_cast<double>(n);
    }
    else if (type == "float")
    {
        float f = std::strtof(input.c_str(), NULL);
        base = static_cast<double>(f);
    }
    else if (type == "double")
    {
        base = std::strtod(input.c_str(), NULL);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (std::isnan(base) || base < 0 || base > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(base)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(base) << "'" << std::endl;

    if (std::isnan(base) || base < INT_MIN || base > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(base) << std::endl;

    float f = static_cast<float>(base);
    std::cout << "float: " << f;
    if (f - static_cast<int>(f) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << base;
    if (base - static_cast<int>(base) == 0)
        std::cout << ".0";
    std::cout << std::endl;
}