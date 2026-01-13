/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:23:10 by iel-asef          #+#    #+#             */
/*   Updated: 2025/08/06 19:23:10 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook PhoneBook;
    std::string command;

    std::cout << "Option : [ADD] - [SEARCH] - [EXIT]\n";
    while (true)
    {
        std::cout << ">> enter command: ";
        std::getline(std::cin, command);
        if (std::cin.eof() || command == "EXIT")
            break;
        else if (command == "ADD")
            PhoneBook.AddContact();
        else if (command == "SEARCH")
            PhoneBook.SearchForContact();
        else
            std::cout << "Error: invalid command" << std::endl;
    }
}