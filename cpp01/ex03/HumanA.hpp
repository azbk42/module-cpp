/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:35:34 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/24 15:48:03 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP


#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(const std::string name, Weapon& weapon);
        ~HumanA();

        void attack() const;

    private:

        Weapon& _weapon;
        const std::string _name;

};

#endif // HUMANA_HPP

