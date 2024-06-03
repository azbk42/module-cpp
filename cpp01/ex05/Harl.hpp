/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:06:30 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/29 17:55:32 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"

class Harl
{
  
    public:

        Harl();
        ~Harl();

        void complain( std::string level );

    private:

        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);
    
    struct hashTable{
        std::string level;
        void (Harl::*function)();
    };
    static const hashTable tab[4];    

};


#endif // HARL_HPP