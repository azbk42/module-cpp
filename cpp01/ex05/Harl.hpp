/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:20:11 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/20 17:41:01 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <map>

class Harl
{
    public:

        Harl();
        ~Harl();

        void complain(std::string level);
  
    private:

        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);

        typedef void (Harl:: *HarlFunction)();
        std::map<std::string, HarlFunction> complainMap;  
};



#endif // HARL_HPP