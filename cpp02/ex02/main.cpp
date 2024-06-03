/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:12 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 15:04:08 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << BLUE << "Test ++: " << RESET << std::endl;
    std::cout << "a   = " << a << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a   = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a   = " << a << std::endl;

    std::cout << BLUE << "b value = " << b << RESET << std::endl;
    std::cout << BLUE << "\nTEST + - * /" << RESET << std::endl;
    std::cout << GREEN << "Init C = a * b" << RESET << std::endl;
    Fixed c = b * 3;
    std::cout << "\nc = " << c  << std::endl;
    c = c / 2;
    std::cout << "c / 2 = " << c  << std::endl;
    c = c - b;
    std::cout << "c - b = " << c << std::endl;
    c = c + Fixed(100);
    std::cout << "c + 100 = " << c << std::endl;
    c = c * Fixed(0.5f);
    std::cout << "c * 0.5 = " << c << std::endl;


    std::cout << BLUE << "\nFind max btw 'a' and 'b':" << RESET << std::endl;
    std::cout << "max = "<< Fixed::max( a, b ) << std::endl;
    std::cout << "min = " << Fixed::min( a, b ) << std::endl;


    std::cout << BLUE << "\nCompare Operator: " << RESET << std::endl;
    std::cout << "if (a < b) :" << std::endl;
    if (a < b)
        std::cout << GREEN << "OK" << RESET << std::endl;
    std::cout << "if (b > a) :" << std::endl;
    if (b > a)
        std::cout << GREEN << "OK" << RESET << std::endl;
        
    std::cout << RED << "\nNOW: a = b" << RESET << std::endl;
    a = b;

    std::cout << "if (a >= b) :" << std::endl;
    if (a >= b)
        std::cout << GREEN << "OK" << RESET << std::endl;
    std::cout << "if (a <= b) :" << std::endl;
    if (a <= b)
        std::cout << GREEN << "OK" << RESET << std::endl;
    std::cout << "if (a == b) :" << std::endl;
    if (a == b)
        std::cout << GREEN << "OK" << RESET << std::endl;
    std::cout << "if (a != b) :" << std::endl;
    if (a != b)
        std::cout << GREEN << "OK" << RESET << std::endl;
    else
        std::cout << RED << "KO" << RESET << std::endl;
        

    return 0;
}