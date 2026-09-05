/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:40:00 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/12 23:45:56 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "===== TEST 1: ShrubberyCreationForm =====" << std::endl;
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm *form1 = intern.makeForm("shrubbery creation", "backyard");
        if (form1)
        {
            boss.signForm(*form1);
            boss.executeForm(*form1);
            delete form1;
        }
    std::cout << "---------------------------------------------" << std::endl;
    
        AForm *form2 = intern.makeForm("robotomy request", "Marvin");
        if (form2)
        {
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }
        
    std::cout << "---------------------------------------------" << std::endl;
        
        AForm *form3 = intern.makeForm("presidential pardon", "Ford Prefect");
        if (form3)
        {
            boss.signForm(*form3);
            boss.executeForm(*form3);
            delete form3;
        }
    
    std::cout << "---------------------------------------------" << std::endl;

        AForm *form4 = intern.makeForm("unknown form", "target");
        if (form4)
            delete form4;
            
    return 0;
}
