/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:21:17 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/20 17:49:39 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::complain(std::string level)
{
    std::map<std::string, HarlFunction>::iterator it = complainMap.find(level);
    if (it != complainMap.end()) {
        (this->*(it->second))();
    } 
    else {
        std::cerr << "Invalid complaint level: " << level << std::endl;
    }
}


void Harl::_debug(void)
{
    std::cout << "DEBUG" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "INFO" << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "WARNING" << std::endl;
}

void Harl::_error(void)
{
    std::cout << "ERROR" << std::endl;
}

Harl::Harl()
{
    complainMap["DEBUG"] = &Harl::_debug;
    complainMap["INFO"] = &Harl::_info;
    complainMap["WARNING"] = &Harl::_warning;
    complainMap["ERROR"] = &Harl::_error; 
}

Harl::~Harl()
{
    
}