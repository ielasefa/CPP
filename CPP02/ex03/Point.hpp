/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:47:08 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/12 09:47:08 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed point_x;
    const Fixed point_y;

    // keep assignment operator private and undefined (objects are immutable because members are const)
    Point &operator=(const Point &src); // assignment operator overload

public:
    Point(); // default constructor
    Point(const float x, const float y); // parameterized constructor 
    Point(const Point &other); // copy constructor
    Fixed getX() const;
    Fixed getY() const;
    ~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const p);
#endif