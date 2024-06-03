/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:58:30 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 14:55:35 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::_nbBits = 8;
const int Fixed::_scale = (1 << _nbBits);

// ######################################################
// #                       MIN MAX                      #
// ######################################################
Fixed& Fixed::max(Fixed & a, Fixed & b)
{
    return (a._value > b._value) ? a : b;
}
const Fixed& Fixed::max(const Fixed & a,const  Fixed & b)
{
    return (a._value > b._value) ? a : b;
}

Fixed& Fixed::min(Fixed & a, Fixed & b)
{
    return (a._value < b._value) ? a : b;
}
const Fixed& Fixed::min(const Fixed & a,const  Fixed & b)
{
    return (a._value < b._value) ? a : b;
}

// ######################################################
// #                       SET GET                      #       
// ######################################################
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

// ######################################################
// #                       OPERATOR -- ++               #       
// ######################################################

Fixed Fixed::operator ++(int)
{
    Fixed tmp(*this);
    ++(*this);

    return (tmp);
}

Fixed & Fixed::operator ++()
{
    _value += 1;
    return (*this);
}

Fixed Fixed::operator --(int)
{
    Fixed tmp(*this);
    --(*this);

    return (tmp);
}

Fixed & Fixed::operator --()
{
    _value -= 1;
    return (*this);
}

// ######################################################
// #                   OPERATOR + - * /                 #       
// ######################################################

Fixed Fixed::operator + (const Fixed & rhs) const
{
    Fixed new_class;

    new_class.setRawBits(this->_value + rhs.getRawBits());

    return (new_class); 
}

Fixed Fixed::operator - (const Fixed & rhs) const
{
    Fixed new_class;

    new_class.setRawBits(this->_value - rhs.getRawBits());

    return (new_class); 
}

Fixed Fixed::operator / (const Fixed & rhs) const
{
    if (rhs.getRawBits() == 0){
        std::cout << "Can't divide by 0";
        return Fixed(-1);
    }
    
    Fixed new_class;
    new_class.setRawBits((this->_value << this->_nbBits) / rhs.getRawBits());

    return (new_class);
}

Fixed Fixed::operator * (const Fixed & rhs) const
{
    Fixed new_class;

    new_class.setRawBits((this->_value * rhs.getRawBits()) >> _nbBits);

    return (new_class);
}

// ######################################################
// #                   COMPARE OPERATOR                 #       
// ######################################################
bool Fixed::operator > (const Fixed & rhs) const 
{
    return (this->_value > rhs._value);
}

bool Fixed::operator < (const Fixed & rhs) const 
{
    return (this->_value < rhs._value);
}

bool Fixed::operator <= (const Fixed & rhs) const
{
    return (this->_value <= rhs._value);
}

bool Fixed::operator >= (const Fixed & rhs) const
{
    return (this->_value >= rhs._value);
}

bool Fixed::operator != (const Fixed & rhs) const
{
    return (this->_value != rhs._value);
}

bool Fixed::operator == (const Fixed & rhs) const
{
    return (this->_value == rhs._value);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #       
// ######################################################

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


// ######################################################
// #                 CONSTRUCTOR                        #       
// ######################################################

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