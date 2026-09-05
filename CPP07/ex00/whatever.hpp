/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:16:30 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/18 03:23:59 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


#include <iostream>

template  <typename T>

void swap( T& a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;   
};

template  <typename T>

const T & max(T &a ,T &b)
{
    return (a > b) ? a : b;
};

template  <typename T>

const T& min(T &a ,T &b)
{
    return (a < b) ? a : b;
};

#endif 