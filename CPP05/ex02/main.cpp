/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:40:00 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/13 18:01:20 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "===== TEST 1: ShrubberyCreationForm =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("home");

        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;

        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: RobotomyRequestForm =====" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");

        std::cout << alice << std::endl;
        std::cout << robot << std::endl;

        alice.signForm(robot);
        alice.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: PresidentialPardonForm =====" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << president << std::endl;
        std::cout << pardon << std::endl;

        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // std::cout << "\n===== TEST 4: Execute unsigned form (should fail) =====" << std::endl;
    // try
    // {
    //     Bureaucrat john("John", 1);
    //     ShrubberyCreationForm shrub2("garden");

    //     john.executeForm(shrub2);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // }

    // std::cout << "\n===== TEST 5: Grade too low to execute =====" << std::endl;
    // try
    // {
    //     Bureaucrat lowGrade("LowGrade", 150);
    //     Bureaucrat highGrade("HighGrade", 1);
    //     RobotomyRequestForm robot2("Target");

    //     highGrade.signForm(robot2);
    //     lowGrade.executeForm(robot2); // Grade too low!
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // }

    return 0;
}
