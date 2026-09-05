/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 00:01:51 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/12 17:10:31 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &src);
        virtual ~AForm();

        
        bool isSigned() const;
        const std::string &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        
        void beSigned(const Bureaucrat &b);
        
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
               const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
               const char* what() const throw();
        };

       class FormNotSignedException : public std::exception
        {
            public:
               const char* what() const throw();
        };
        
};

std::ostream &operator<<(std::ostream &out, const AForm &Aform);
    
#endif
