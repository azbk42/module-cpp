/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:12 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 10:34:24 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) 
{
    std::cout << GREEN << "Creation instance a:" << RESET << std::endl;
    Fixed a;
    std::cout << RED << "Call getRawbits for a:" << RESET << std::endl;
    std::cout << a.getRawBits() << std::endl;
    
    std::cout << GREEN << "SetRawBits 3200:" << RESET << std::endl;
    a.setRawBits(3200);
    std::cout << RED << "Call getRawbits for a after set at 3200:" << RESET << std::endl;
    std::cout << a.getRawBits() << std::endl;
    
    std::cout << GREEN << "Constructor by copie call" 
                    << "b copy a"
                    << RESET << std::endl;
    Fixed b( a );
    std::cout << RED << "Call getRawbits for b:" << RESET << std::endl;
    std::cout << b.getRawBits() << std::endl;

    std::cout << GREEN << "Creation instance c:" << RESET << std::endl;
    Fixed c;
    std::cout << RED << "Call getRawbits for c just after init:" << RESET << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << GREEN << "Surcharge operator affectation c = b" << RESET << std::endl;
    c = b;
    std::cout << RED << "Call getRawbits for c:" << RESET << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    return 0;
}