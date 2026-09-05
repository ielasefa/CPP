/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:26:12 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/12 17:50:39 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;

    public:
    PresidentialPardonForm (const std::string &target);
    PresidentialPardonForm (const PresidentialPardonForm &copy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
    ~PresidentialPardonForm ();
    
    void    execute(Bureaucrat const &executor) const;
};

#endif