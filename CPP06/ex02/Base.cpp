/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:17:51 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/15 23:23:38 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>

Base::~Base()
{}

Base* generate()
{
    int i = rand() % 3;
    
      if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else
        return new C();
}