/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:58:30 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/25 18:53:08 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

// constante:
const int Fixed::_nbBits = 8;
const float Fixed::_scale = 1 << Fixed::_nbBits;

// Public Method:
int Fixed::toInt(void) const
{
    return (_value >> _nbBits);
}

float Fixed::toFloat(void) const
{
    float value_to_float;

    value_to_float = (_value / _scale);
    return (value_to_float);
} 

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

// surcharge operator:
Fixed& Fixed::operator << (const Fixed& other)
{
    
}

Fixed& Fixed::operator=(const Fixed& other) 
{
    if (this != &other) {
        _value = other._value;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

// Constructor 

Fixed::Fixed(const float number)
{
    int integer_number = static_cast<int>(number);
    float float_number = number - integer_number;
    
    _value = (integer_number << _nbBits) + static_cast<int>(roundf((float_number * _scale)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
    _value = number << _nbBits;
    std::cout << "Int constructor called" << std::endl;
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