/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:10:26 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 17:46:02 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float left_or_right(Point const p, Point const v1, Point const v2)
{
    float first_part;
    float second_part;
    float result;

    first_part = (v2.getX() - p.getX()) * (v1.getY() - p.getY());
    second_part = (v2.getY()- p.getY()) * (v1.getX() - p.getX());
    
    result = first_part - second_part;
    return (result);
}

static bool is_in_triangle(Point const p, Point const v1, Point const v2, Point const v3)
{
    float first;
    float second;
    float third;

    first = left_or_right(p, v1, v2);
    second = left_or_right(p, v2, v3);
    third = left_or_right(p, v3, v1);

    if (first == 0 || second == 0|| third == 0){
        std::cout<< RED << "Sorry point P is touching one segment" << RESET << std::endl;
        return (false);
    }
    else if (first > 0 && second > 0 && third > 0){
        std::cout << GREEN << "Congrats P fit in the triangle !! (clockwise)" << RESET << std::endl;
        return (true);
    }
    else if (first < 0 && second < 0 && third < 0){
        std::cout << GREEN << "Congrats P fit in the triangle !! (counterclockwise)" << RESET << std::endl;
        return (true);
    }
    else{
        std::cout<< RED << "Sorry point P doesn't fit in :(" << RESET << std::endl;
        return (false);
    }
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    return (is_in_triangle(point, a, b, c));
}