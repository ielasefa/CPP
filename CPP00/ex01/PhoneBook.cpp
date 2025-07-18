#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
    contactCount = 0;
    oldContactIndex = 0;
}

void PhoneBook::AddContact()
{
    std::string fname, lname, nick, phone, secret;

    std::cout << "First name    : ";
    fname = getlineHelper();
    std::cout << "Last name     : ";
    lname = getlineHelper();
    std::cout << "Nick name     : ";
    nick = getlineHelper();
    std::cout << "Phone number  : ";
    phone = getlineHelper();
    for (std::size_t i = 0; i < phone.length(); i++)
    {
        if (!isdigit(phone[i])){
            std::cout << "Error: phone number must be digits" << std::endl;
            return;
        }
    }
    std::cout << "Darkest secret: ";
    secret = getlineHelper();
    if (fname.empty() || lname.empty() || nick.empty() || phone.empty() || secret.empty()) {
        std::cout << "Error: all fields must be filled" << std::endl;
        return;
    }
    contact[oldContactIndex].setContact(fname, lname, nick, phone, secret);
    oldContactIndex = (oldContactIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;

    std::cout << ">>> Contact added <<<" << std::endl;
}

void PhoneBook::SearchForContact() const
{
    if (contactCount == 0) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < contactCount; i++) {
        std::cout << "|" << std::setw(10) << i
                  << "|" << std::setw(10) << formatField(contact[i].getFirstName())
                  << "|" << std::setw(10) << formatField(contact[i].getLastName())
                  << "|" << std::setw(10) << formatField(contact[i].getNickname())
                  << "|" << std::endl;
    }
    std::cout << "Enter index: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.length() != 1 || !isdigit(input[0])) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    int idx = input[0] - '0';
    if (idx < 0 || idx >= contactCount) {
        std::cout << "Index out of range." << std::endl;
        return;
    }
    contact[idx].displayContact();
}

std::string formatField(const std::string &field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return std::string(10 - field.length(), ' ') + field;
}

std::string getlineHelper()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}