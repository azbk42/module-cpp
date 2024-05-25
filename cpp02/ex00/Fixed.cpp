/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:58:30 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/25 14:34:39 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
    std::cout << raw << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
    if (this != &other) {
        _value = other._value;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::Fixed(const Fixed& other): _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}