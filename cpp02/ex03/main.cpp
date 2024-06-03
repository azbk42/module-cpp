/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:12 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 17:54:18 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

static void test_unitaire_clockwise(void)
{
    Point vector1(1, 1);
    Point vector2(4, 5);
    Point vector3(7, 1);

    Point P1(4, 3);
    std::cout << "Test 1 (Point Inside Clockwise): \n" 
              << (bsp(vector1, vector2, vector3, P1) ? GREEN "Passed" RESET : BLUE "Failed" RESET) 
              << std::endl;
}

static void test_unitaire_counterclockwise(void)
{
    Point vector1_reverse(7, 3);
    Point vector2_reverse(4, 6);
    Point vector3_reverse(4, 3);
    
    Point P2(4.5f, 5);
    std::cout << "Test 2 (Point Inside Counterclockwise): \n" 
              << (bsp(vector1_reverse, vector2_reverse, vector3_reverse, P2) ? GREEN "Passed" RESET : RED "Failed" RESET) 
              << std::endl;

    Point P3(3, 4);
    std::cout << "Test 3 (Point Outside): \n" 
              << (!bsp(vector1_reverse, vector2_reverse, vector3_reverse, P3) ? GREEN "Passed" RESET : RED "Failed" RESET) 
              << std::endl;

    Point P4(4, 3);
    std::cout << "Test 4 (Point on Vector): \n" 
              << (!bsp(vector1_reverse, vector2_reverse, vector3_reverse, P4) ? GREEN "Passed" RESET : RED "Failed" RESET) 
              << std::endl;

    Point P5(5, 3);
    std::cout << "Test 5 (Point on Segment): \n" 
              << (!bsp(vector1_reverse, vector2_reverse, vector3_reverse, P5) ? GREEN "Passed" RESET : RED "Failed" RESET) 
              << std::endl;

}

int main(void) 
{
    test_unitaire_clockwise();
    test_unitaire_counterclockwise();
    
    return (0);
}