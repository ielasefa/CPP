/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:47:25 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/23 21:24:29 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>

static float area(Point const a, Point const b, Point const c)
{
    return fabs(
        (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
         b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
         c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f
    );
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    float A  = area(a, b, c);
    float A1 = area(p, b, c);
    float A2 = area(a, p, c);
    float A3 = area(a, b, p);

    if (A1 == 0 || A2 == 0 || A3 == 0)  
        return false;
    return fabs((A1 + A2 + A3) - A) == 0;
}
