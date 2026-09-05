/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:36:28 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/12 20:10:26 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>

void iter(T * array , int length,void (*f) (T & ))
{
    for(int i = 0; i < length ; i++)
        f(array[i]);
}

template <typename T>

void iter(T * array , int length,void (*f) (const T & ))
{
    for(int i = 0; i < length ; i++)
        f(array[i]);
}

#endif