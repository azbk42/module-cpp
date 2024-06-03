/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:10:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 16:19:34 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
    
    public:

        float getX(void) const;
        float getY(void) const;
        Point(const Point & rhs);
        Point(float x, float y);
        Point();
        ~Point();

        Point& operator = (const Point & rhs);
    private:

        const Fixed _x;
        const Fixed _y;

};