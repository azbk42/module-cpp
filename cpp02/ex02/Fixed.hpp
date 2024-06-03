/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 14:29:35 by emauduit         ###   ########.fr       */
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
#define BLUE    "\033[34m"

class Fixed
{
    
    public:
        
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);

        int getRawBits(void) const; 
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed(const float value);
        Fixed(const int value);
        Fixed(const Fixed& other);
        Fixed();
        ~Fixed();

        bool operator > (const Fixed & rhs) const ;
        bool operator < (const Fixed & rhs) const ;
        bool operator <= (const Fixed & rhs) const ;
        bool operator >= (const Fixed & rhs) const ;
        bool operator != (const Fixed & rhs) const ;
        bool operator == (const Fixed & rhs) const ;
        
        Fixed operator + (const Fixed & rhs) const;
        Fixed operator - (const Fixed & rhs) const;
        Fixed operator / (const Fixed & rhs) const;
        Fixed operator * (const Fixed & rhs) const;

        Fixed & operator ++();
        Fixed operator ++(int);
        Fixed operator --(int);
        Fixed & operator --();
        
        Fixed& operator = (const Fixed& rhs);
    private:

        int _value; 
        static const int _nbBits;
        static const int _scale;
};

std::ostream & operator << (std::ostream & o, Fixed const & rhs);

#endif