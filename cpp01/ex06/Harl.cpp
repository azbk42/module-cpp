/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:21:17 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/24 15:42:47 by emauduit         ###   ########.fr       */
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

int Harl::getIndex( std::string level )
{
    for (int i = 0; i < 4; i++){
        if (tab[i].level == level){
            return (i);
        }
    }
    return (-1);    
}

void Harl::complain(std::string level) 
{
    int index = getIndex(level);

    switch (index) {
        case 0:
            std::cout << "[ " << tab[0].level << " ]" << std::endl;
            (this->*(tab[0].function))();
            std::cout << std::endl;
        case 1:
            std::cout << "[ " << tab[1].level << " ]" << std::endl;
            (this->*(tab[1].function))();
            std::cout << std::endl;
        case 2:
            std::cout << "[ " << tab[2].level << " ]" << std::endl;
            (this->*(tab[2].function))();
            std::cout << std::endl;
        case 3:
            std::cout << "[ " << tab[3].level << " ]" << std::endl;
            (this->*(tab[3].function))();
            break;
        default:
            std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
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