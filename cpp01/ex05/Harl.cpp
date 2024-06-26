/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:06:14 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/24 15:44:55 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

const Harl::hashTable Harl::tab[4] = {
    
    {"DEBUG", &Harl::_debug},
    {"INFO", &Harl::_info},
    {"WARNING", &Harl::_warning},
    {"ERROR", &Harl::_error},
};

void Harl::complain( std::string level )
{
    for (int i = 0; i < 4; i++){
        if (tab[i].level == level){
            (this->*(tab[i].function))();
            return ;
        }
    }    
    std::cerr << "Invalid complaint level: " << level << std::endl;
}

void Harl::_debug(void)
{
    std::cout << "I love having extra bacon for" 
            << "my 7XL-double-cheese-triple-pickle-special-"
            << "ketchup burger. I really do !" << std::endl;
}
void Harl::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money." 
            << "You didn't put enough bacon in my burger !"
            << "If you did, I wouldn't be asking for more !" << std::endl;
    
}
void Harl::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free."
            << "I've been coming for years " 
            << "whereas you started working here since last month." << std::endl;
    
}
void Harl::_error(void)
{
    std::cout << "This is unacceptable !"
            << "I want to speak to the manager now" << std::endl;    

}

Harl::~Harl()
{
    
}

Harl::Harl()
{
    
}