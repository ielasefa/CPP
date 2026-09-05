/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:02:30 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/12 00:44:59 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}
 Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request","presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            AForm *form = NULL;
            switch (i)
            {
                case 0:
                    form = new ShrubberyCreationForm(target);
                    break;
                case 1:
                    form = new RobotomyRequestForm(target);
                    break;
                case 2:
                    form = new PresidentialPardonForm(target);
                    break;
            }
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cout << "Intern cannot create form: unknown form name \"" << formName << "\"" << std::endl;
    return NULL;
}