/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:10:40 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 17:18:55 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// ######################################################
// #                      GET                           #       
// ######################################################

float Point::getX(void) const
{
    return (_x.toFloat());
}

float Point::getY(void) const
{
    return (_y.toFloat());
}

// ######################################################
// #                 OVERLOAD OP                        #       
// ######################################################

Point& Point::operator=(const Point& rhs)
{
    if (this != &rhs) {
        const_cast<Fixed&>(_x) = rhs._x;
        const_cast<Fixed&>(_y) = rhs._y;
    }
    return *this;
}

// ######################################################
// #                 CONSTRUCTOR                        #       
// ######################################################

Point::Point(const Point& rhs): _x(rhs._x), _y(rhs._y) {};
Point::Point(float x, float y): _x(x), _y(y) {};
Point::Point():  _x(0), _y(0){};
Point::~Point() {};