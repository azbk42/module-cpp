/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:20:11 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/24 15:42:55 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl
{
  
    public:

        Harl();
        ~Harl();

        void complain(std::string level);

    private:

        int getIndex(std::string level);
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