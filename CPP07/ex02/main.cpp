/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:05:02 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/14 18:07:07 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "===== Test Array<int> =====" << std::endl;

    Array<int> intArray(3);
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;

    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

    std::cout << "\n===== Test Access Ghalt (Exception) =====" << std::endl;

    try
    {
        std::cout << intArray[10] << std::endl; 
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test Array<char> =====" << std::endl;

    Array<char> charArray(4);
    charArray[0] = 'A';
    charArray[1] = 'B';
    charArray[2] = 'C';
    charArray[3] = 'D';

    for (unsigned int i = 0; i < charArray.size(); i++)
        std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;

    return 0;
}
