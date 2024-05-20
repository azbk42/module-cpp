/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:44:54 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/20 16:00:20 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{

    public:
        HumanB(std::string name);
        HumanB();
        ~HumanB();
    
        void attack() const;
        void setWeapon(Weapon& weapon);
        
    private:

        Weapon* _weapon;
        std::string _name;

};

#endif // HUMANB_HPP