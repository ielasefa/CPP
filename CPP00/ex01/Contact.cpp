/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:23:00 by iel-asef          #+#    #+#             */
/*   Updated: 2025/08/06 19:23:00 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

void Contact::setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
    firstName = fn;
    lastName = ln;
    nickname = nn;
    phoneNumber = pn;
    darkestSecret = ds;
}

std::string Contact::getFirstName() 
{
    return firstName;
}

std::string Contact::getLastName() 
{
    return lastName;
}

std::string Contact::getNickname() 
{
    return nickname;
}

std::string Contact::getPhoneNumber() 
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() 
{
    return darkestSecret;
}

void Contact::displayContact() 
{
    std::cout << "First Name    : " << firstName << std::endl;
    std::cout << "Last Name     : " << lastName << std::endl;
    std::cout << "Nickname      : " << nickname << std::endl;
    std::cout << "Phone Number  : " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}