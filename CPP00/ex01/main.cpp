#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook PhoneBook;
    std::string command;

    std::cout << "Option : [ADD] - [SEARCH] - [EXIT]\n";
    while (true) {
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