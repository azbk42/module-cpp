/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:41:04 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/24 14:03:43 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
    
        const std::string& getType(void) const;
        void setType(std::string str);


    private:
        std::string _type;
};

#endif // WEAPON_HPP
