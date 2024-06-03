/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:25:09 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/29 14:36:50 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string.h>

class Zombie
{
    public:

        void announce(void);

        Zombie();
        Zombie(std::string name);
        ~Zombie(void);

    private:

        std::string _name;

};

Zombie* zombieHorde( int N, std::string name );

#endif