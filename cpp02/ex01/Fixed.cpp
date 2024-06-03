/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:58:30 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 11:51:39 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::_nbBits = 8;
const int Fixed::_scale = (1 << _nbBits);

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;    
}

float Fixed::toFloat( void ) const
{
    float convert = static_cast<float>(_value);
    
    return (convert / _scale);
}

int Fixed::toInt(void) const
{
    return (_value >> _nbBits);
}

// overload operator

std::ostream & operator << (std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}

Fixed & Fixed::operator = (const Fixed & rhs)
{
    if (this != &rhs){
        this->_value = rhs.getRawBits();
    }
    return (*this);
}

// constructor
Fixed::Fixed(const int value)
{
    _value = value << _nbBits;
}
Fixed::Fixed(const float value)
{
    _value = roundf(value * _scale);
}
Fixed::Fixed(const Fixed& rhs): _value(rhs._value) {};
Fixed::Fixed(): _value(0) {};
Fixed::~Fixed() {};