/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/25 14:30:56 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
  
    public:

        int getRawBits(void) const; 
        void setRawBits(int const raw);

        Fixed(const Fixed& other);
        Fixed();
        ~Fixed();

        Fixed& operator = (const Fixed& other);

    private:

        int _value; 
        static const int _nbBits = 8;
};

#endif