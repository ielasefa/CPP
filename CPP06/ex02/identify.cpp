/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:09:35 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/16 19:44:55 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"
#include <typeinfo>


void identify(Base* p)
{
    if(dynamic_cast<A*>(p)!= NULL)
        std::cout << "A" << std::endl;
    
    else if(dynamic_cast<B*>(p)!= NULL)
        std::cout << "B" << std::endl;

    else if(dynamic_cast<C*>(p)!= NULL)
        std::cout << "C" << std::endl;
        
    else 
        std::cout <<"Unknowntype" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    std::cout << "Unknown Type" << std::endl;
}