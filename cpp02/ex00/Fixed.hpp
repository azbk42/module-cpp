/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 10:27:01 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

class Fixed
{
  
    public:

        int getRawBits(void) const; 
        void setRawBits(int const raw);

        Fixed(const Fixed& rhs);
        Fixed();
        ~Fixed();

        Fixed& operator = (const Fixed& rhs);

    private:

        int _value; 
        static const int _nbBits = 8;
};

#endif