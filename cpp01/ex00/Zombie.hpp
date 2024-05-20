/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:03:17 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/19 13:14:46 by emauduit         ###   ########.fr       */
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

    Zombie(std::string name);
    ~Zombie(void);

private:

    std::string _name;

};

Zombie* newZombie(std::string name);
void randomChump( std::string name );


#endif