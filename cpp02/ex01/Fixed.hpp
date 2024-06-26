/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 12:10:27 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

class Fixed
{
    
    public:

        int getRawBits(void) const; 
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed(const float value);
        Fixed(const int value);
        Fixed(const Fixed& other);
        Fixed();
        ~Fixed();

        Fixed& operator = (const Fixed& rhs);
    private:

        int _value; 
        static const int _nbBits;
        static const int _scale;
};

std::ostream & operator << (std::ostream & o, Fixed const & rhs);

#endif