/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:58:30 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 10:30:43 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

// overload operator

Fixed& Fixed::operator = (const Fixed& rhs)
{
    if (this != &rhs){
        this->_value = rhs.getRawBits();
    }
    
    return (*this);
}

// constructor:

Fixed::Fixed(const Fixed& rhs): _value(rhs._value) {}

Fixed::Fixed(): _value(0) {}

Fixed::~Fixed() {}