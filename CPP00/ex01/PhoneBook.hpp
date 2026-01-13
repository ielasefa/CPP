/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:23:18 by iel-asef          #+#    #+#             */
/*   Updated: 2025/10/11 17:26:18 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
    private:

        Contact contact[8]; 
        int contactCount; // attributes
        int oldContactIndex;
    
    public:

        PhoneBook(); // constructor
        void AddContact(); //method
        void SearchForContact() ; 
};

std::string formatField(const std::string &field);
std::string getlineHelper(); 
#endif