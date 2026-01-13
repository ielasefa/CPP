/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:47:11 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/12 09:47:11 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : point_x(0), point_y(0) {}

Point::Point(const float x, const float y)
    : point_x(x), point_y(y) {}

Point::Point(const Point &other)
    : point_x(other.point_x), point_y(other.point_y) {}

Fixed Point::getX() const
{
    return point_x;
}

Fixed Point::getY() const
{
    return point_y;
}

Point::~Point() {}