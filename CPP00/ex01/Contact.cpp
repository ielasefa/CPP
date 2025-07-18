#include "Contact.hpp"
#include <iostream>

void Contact::setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) {
    firstName = fn;
    lastName = ln;
    nickname = nn;
    phoneNumber = pn;
    darkestSecret = ds;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const 
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}

void Contact::displayContact() const
{
    std::cout << "First Name    : " << firstName << std::endl;
    std::cout << "Last Name     : " << lastName << std::endl;
    std::cout << "Nickname      : " << nickname << std::endl;
    std::cout << "Phone Number  : " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
