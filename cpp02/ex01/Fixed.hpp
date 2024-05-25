/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/25 18:13:50 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>

class Fixed
{
    
    public:

        int toInt(void) const;
        float toFloat(void) const;
        int getRawBits(void) const; 
        void setRawBits(int const raw);

        Fixed(const float value);
        Fixed(const int value);
        Fixed(const Fixed& other);
        Fixed();
        ~Fixed();

        Fixed& operator = (const Fixed& other);
        Fixed& operator << (const Fixed& other);

    private:

        int _value; 
        static const float _scale;
        static const int _nbBits;
};

#endif